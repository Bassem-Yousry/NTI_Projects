/*
 * ADC_config.h
 *
 * Created: 2/25/2023 9:24:39 AM
 *  Author: amrba
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define AREF	    0  //Internal Vref turned off
#define aVCC		1
#define Internal    3  //2.56V Voltage Reference with external capacitor at AREF pin

#define ADC_div_128   7
#define ADC_div_64    6
#define ADC_div_32    5
#define ADC_div_16    4
#define ADC_div_8     3
#define ADC_div_4     2
#define ADC_div_2     1

#define FREE_RUNNING                0
#define ANALOG_COMPARATOR	        1
#define EXTERNAL_INTERRUPT_REQUEST  2
#define Timer0_Compare_Match	    3
#define Timer0_Overflow			    4
#define Timer_Compare_Match_B	    5
#define Timer1_Overflow			    6
#define Timer1_Capture_Event	    7

#define SINGLE_CONVERSION_MODE      8


//NOTE AUTO TRIGGER MODE STILL INCOMPLETED
#define TRIGGER_MODE             SINGLE_CONVERSION_MODE
#define ADC_Division_Factor      ADC_div_128
#define ADC_VOLTAGE_REFERENCE    aVCC
#define ADC_EnableInt			 0

#endif /* ADC_CONFIG_H_ */