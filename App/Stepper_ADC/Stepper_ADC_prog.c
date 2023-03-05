/*
* Stepper_ADC_prog.c
*
* Created: 3/5/2023 10:33:02 PM
*  Author: amrba
*/


#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "Stepper_interface.h"
#include "Stepper_config.h"
static u16 DelayMs=1;
static StepperDir STPDir=CLKWise;
void StepperDelay(){
	for (int i=0;i<=DelayMs;i++)
	{
		_delay_ms(1);
	}
	
}
void Stepper_ADC_init(){
	LCD_init();
	ADC_init();
	Timer0_Init(Normal);
	Stepper_ADC_Dir(CLKWise);
	DIO_SetPinDir(StepperCOL1,OUTPUT);
	DIO_SetPinDir(StepperCOL2,OUTPUT);
	DIO_SetPinDir(StepperCOL3,OUTPUT);
	DIO_SetPinDir(StepperCOL4,OUTPUT);
	Timer0_start();
}
void Stepper_ADC_Dir(StepperDir Dir){
	STPDir=Dir;
}
void Stepper_ADC_Speed(u16 Speed){
	if (Speed>=100)
	{
		return;
	}
	
	DelayMs=100-Speed;
}
void Stepper_ADC_Start(){
	f64 Temp;
	u8 i=0;
	while(1){
		Temp=ADC_Read(ADC0);
		Temp*=(100.0/1023);
		Stepper_ADC_Speed(Temp);
		
		
		if (Temp==0)
		{
			_delay_ms(500);
			LCD_ClearDisplay();
			continue;
		}
		else if (STPDir==CLKWise)
		{
			i=(i+1)%4;			
		}
		else if (STPDir==AntiCLKWise)
		{
			i--;
			if (i>3)
			{
				i=3;
			}
		}
		DIO_TogPinValue(StepperPort,i);
		StepperDelay();
		LCD_ClearDisplay();
	}
}