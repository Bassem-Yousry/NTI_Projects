/*
 * DC_ADC.c
 *
 * Created: 3/3/2023 10:24:22 AM
 *  Author: amrba
 */ 
#include "../../HAL/Keypad/Keypad_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"

void DC_ADC_init(){
	LCD_init();
	ADC_init();	
	Timer0_Init(FastPWM);
	Timer0_start();	
}
void DC_ADC_start()
{
	f64 Temp;
	while (1)
	{
		Temp=ADC_Read(ADC0);
		Temp*=(100.0/1023);
		Timer0SetDutyCycle(Temp);
		LCD_WriteNUM(Temp);
		_delay_ms(100);
		LCD_ClearDisplay();
	}
	
}