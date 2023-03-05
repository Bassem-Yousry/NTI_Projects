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

u16 TIM1TopValue=0xff;
void Timer1_SetTop(u16 Top){
	TIM1TopValue=Top;
	#if TIM1ModeNum == 14
	ICR1L=Top;
	#endif
}
void Timer1_SetFreq(u32 Freq){
	u32 TopValue=0xff;
	u32 CLKPreScaler=TIM1CLK_PSSelect;	
		switch(CLKPreScaler){
			case CLK_NoPS:CLKPreScaler=1;
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
	TopValue=(double)CLKFreq/(Freq*CLKPreScaler);
	Timer1_SetTop(TopValue);	
}
void Timer1_SetDutyCycle(f64 DutyCycle){
		OCR1AL=( DutyCycle/100.0) *TIM1TopValue;
}
void Timer1_Init(){
	#if TIM1ModeNum == 14
	TCCR1A=0x82;
	TCCR1B=0x18;
	#endif
	//ClkSelect
	TCCR1B |=(TIM1CLK_PSSelect);

}

void Timer0_Init(TimerMode TIM0_Mode){
	TCCR0 |=(CompareMatchOutput<<4);
	#if EnableOFInt
	SET_BIT(TIMSK,0);
	#endif
	#if EnableCMPInt
	SET_BIT(TIMSK,1);
	#endif
	switch(TIM0_Mode){
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
	CLR_BIT(TCCR0,2);
	TCCR0 |=(ClockPrescalerSelect);
}
void Timer0_stop(){
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
}
u32 Timer0DelayMS_NonBlocking(f64 DelayMS ,void(*handler)()){
	// Return No. of OverFlows
	Timer0_start();
	SET_BIT(TIMSK,0);//enable OF Int
	Timer0_SetHandler(handler);
	u32 CLKPreScaler=1;
	u32 Reminder=0;
	DelayMS/=1000;
	
	switch(ClockPrescalerSelect){
		case CLK_NoPS:CLKPreScaler=1;
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
	u32 CLKPreScaler=ClockPrescalerSelect;
	u32 Reminder=0;
	DelayMS/=1000;
	
	switch(CLKPreScaler){
		case CLK_NoPS:CLKPreScaler=1;
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
