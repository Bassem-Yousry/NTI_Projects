/*
* ADC_prog.c
*
* Created: 2/25/2023 9:23:28 AM
*  Author: amrba
*/


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"


void ADC_init(){
	
	ADMUX= (ADC_VOLTAGE_REFERENCE<<6);
	ADCSRA=ADC_Division_Factor;

	#if ADC_EnableInt
	SET_BIT(ADCSRA,3);
	#endif

	#if TRIGGER_MODE==SINGLE_CONVERSION_MODE
	CLR_BIT(ADCSRA,5);
	#else
	SET_BIT(ADCSRA,5);
	SFIOR=TRIGGER_MODE<<5;
	#endif
	SET_BIT(ADCSRA,7);//enable
}

u16 ADC_Read(u8 ADC_Channel){

	ADMUX = (ADMUX & 0xE0) | ADC_Channel;
	SET_BIT(ADCSRA,6);//start conversion
	while(GET_BIT(ADCSRA,4)==0);
	return (ADCDATA & 0x03ff);
}