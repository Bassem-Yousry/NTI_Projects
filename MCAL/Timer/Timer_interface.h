/*
 * Timer_interface.h
 *
 * Created: 2/26/2023 10:38:27 AM
 *  Author: amrba
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "../../STD_TYPES.h"

typedef enum {Normal,PWM_PC,CTC,FastPWM}TimerMode;
	
void Timer0_Init(TimerMode);
void Timer0_start();
void Timer0_stop();
void Timer0DelayMS_Blocking(f64 DelayMS );
u32 Timer0DelayMS_NonBlocking(f64 DelayMS ,void(*handler)());
void Timer0SetDutyCycle(u8 DutyCycle);
void Timer0_SetCompareValue(u8 CMP_Value);
void Timer0_SetHandler(void(*Handeler)(void));



#endif /* TIMER_INTERFACE_H_ */