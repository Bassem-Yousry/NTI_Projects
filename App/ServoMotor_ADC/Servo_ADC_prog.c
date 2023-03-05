/*
 * DC_ADC.c
 *
 * Created: 3/3/2023 10:24:22 AM
 *  Author: amrba
 */ 
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/Timer/Timer_private.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "Servo_ADC_interface.h"
void Servo_ADC_init(){
	DIO_SetPinDir(DIO_PORTD,PIN5,OUTPUT);
	LCD_init();
	ADC_init();	
	Timer1_SetFreq(50);	 
	Servo_ADC_SetAngle(90);//Default Position
	Timer1_Init();
}
void Servo_ADC_SetAngle(u8 Angle){
	// map Angle 0->180  to   Duty Cycle  5 ->10
	f64 DutyCycle=2.5+(Angle*10.0/180.0);
	Timer1_SetDutyCycle(DutyCycle);
}
void Servo_ADC_start()
{
	f64 Temp;
	while (1)
	{
		Temp=ADC_Read(ADC0);
		Temp*=(180.0/1023);
		Servo_ADC_SetAngle(Temp);
		LCD_DisplayString("ANGLE = ");
		LCD_WriteNUM(Temp);
		_delay_ms(100);
		LCD_ClearDisplay();
	}
	
}