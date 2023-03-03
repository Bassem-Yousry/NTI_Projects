/*
* Timer_prog.c
*
* Created: 2/26/2023 10:37:39 AM
*  Author: amrba
*/
#include "Timer_interface.h"
#include "Timer_config.h"
#include "Timer_private.h"
#include "../DIO/DIO_Interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "avr/interrupt.h"
void (*Timer0CallBackFunc)();

void Timer0_Init(TimerMode TIMMode){
	TCCR0 |=(CompareMatchOutput<<4);
	//SET_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);
	#if EnableOFInt
	SET_BIT(TIMSK,0);
	#endif
	#if EnableCMPInt
	SET_BIT(TIMSK,1);
	#endif
	switch(TIMMode){
		case Normal:
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
		break;
		case CTC:
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		break;
		case FastPWM:
		DIO_SetPinDir(DIO_PORTB,PIN3,OUTPUT);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		break;
		case PWM_PC:
		DIO_SetPinDir(DIO_PORTB,PIN3,OUTPUT);
		SET_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
		break;
		default:break;
	}
}
void Timer0_start(){
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	TCCR0 |=(ClockSelect);
}
void Timer0_stop(){
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
}
u32 Timer0DelayMS_NonBlocking(f64 DelayMS ,void(*handler)()){
	Timer0_start();
	SET_BIT(TIMSK,0);//enable OF Int
	Timer0_SetHandler(handler);
	u32 CLKPreScaler=1;
	u32 Reminder=0;
	DelayMS/=1000;
	
	switch(ClockSelect){
		case CLK:CLKPreScaler=1;
		break;
		case CLK_8:CLKPreScaler=8;
		break;
		case CLK_64:CLKPreScaler=64;
		break;
		case CLK_256:CLKPreScaler=256;
		break;
		case CLK_1024:CLKPreScaler=1024;
		break;
		default:break;
	}
	u32 NumOF= DelayMS*CLKFreq/(256.0*CLKPreScaler);	
	return NumOF;
	
}
void Timer0DelayMS_Blocking(f64 DelayMS ){
	Timer0_start();
	CLR_BIT(TIMSK,0);//disable OF Int
	u32 CLKPreScaler=1;
	u32 Reminder=0;
	DelayMS/=1000;
	
	switch(ClockSelect){
		case CLK:CLKPreScaler=1;
		break;
		case CLK_8:CLKPreScaler=8;
		break;
		case CLK_64:CLKPreScaler=64;
		break;
		case CLK_256:CLKPreScaler=256;
		break;
		case CLK_1024:CLKPreScaler=1024;
		break;
		default:break;
	}
	u32 NumOF= DelayMS*CLKFreq/(256.0*CLKPreScaler);
	for(u32 i=0;i<NumOF;i++){
		while(GET_BIT(TIFR,0)==0);
		SET_BIT(TIFR,0);
	}
	//if ((256*CLKPreScaler/CLKFreq)!=0)
	//{
	//		Reminder=DelayMS%(256*1000L*CLKPreScaler/CLKFreq);
	//}
	//TCCR0=256-Reminder;
	//while(GET_BIT(TIFR,0)==0);
	//SET_BIT(TIFR,0);
}

void Timer0_SetCompareValue(u8 CMP_Value){
	OCR0=CMP_Value;
}

void Timer0SetDutyCycle(u8 DutyCycle){
	
	OCR0=( (float)DutyCycle/100.0) *255;
}

void Timer0_SetHandler(void(*Handeler)(void)){
	Timer0CallBackFunc=Handeler;
}
ISR(TIMER0_OVF_vect){
	Timer0CallBackFunc();
}
