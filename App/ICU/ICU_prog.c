/*
 * ICU_prog.c
 *
 * Created: 3/6/2023 12:53:15 AM
 *  Author: amrba
 */ 
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/Timer/Timer_private.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "ICU_config.h"
#include "ICU_interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

void ICU_init(){
	
	//measure freq and duty cycle of OC0
	LCD_init();
	ADC_init();
	DIO_SetPinDir(DIO_PORTB,PIN3,OUTPUT);
	//DIO_SetPinDir(DIO_PORTD,PIN6,INPUT);
	//DIO_SetPinValue(DIO_PORTD,PIN6,HIGH);
	Timer0_Init(FastPWM);
	Timer0_start();
	Timer1_Init();
}
void ICU_start(){
	
	u16 E1,E2,E3;
	f64 duty=0,freq=0;
	
	f64 Temp;
	while (1)
	{
		
		Temp=ADC_Read(ADC0);
		Temp*=(100.0/1023);
		Timer0SetDutyCycle(Temp);
		
		E1=Timer1_DetectEdge(Rising);
		E2=Timer1_DetectEdge(Falling);
		E3=Timer1_DetectEdge(Rising);
		if (E2<E1||E3<E2)
		{
			continue;
		}
		duty=(f64)(E2-E1)/(E3-E1);
		duty*=100;
		freq=F_CPU/(E3-E1);
		LCD_WriteNUM(duty);
		LCD_goto(1,0);
		LCD_WriteNUM(freq);
		_delay_ms(1000);
		LCD_ClearDisplay();
	}
}