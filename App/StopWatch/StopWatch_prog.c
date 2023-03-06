/*
 * StopWatch_prog.c
 *
 * Created: 3/6/2023 3:05:15 AM
 *  Author: amrba
 */ 
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include <stdio.h>
#include "../../MCAL/Timer/Timer_interface.h"

void SW_Init(){
	LCD_init();
	Timer0_Init(Normal);
}
void SW_Start(){
	u8 seconds =0;
	u8 min=0;
	u8 hours=0;
	char Time[15]={0};
	while(1){
		if (seconds==59)
		{
			if (min==59)
			{
				hours++;
			}
			min=(min+1)%60;
		}
		seconds=(seconds+1)%60;
		sprintf(Time,"%02i:%02i:%02i",hours,min,seconds);
		LCD_DisplayString(Time);
		Timer0DelayMS_Blocking(1000);
		//_delay_ms(1000);
		LCD_ClearDisplay();
	}
}
	