/*
 * ADC_interface.h
 *
 * Created: 2/25/2023 9:24:23 AM
 *  Author: amrba
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "../../STD_TYPES.h"
typedef enum {ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7}ADC_CH;

void ADC_init();
u16 ADC_Read(u8 ADC_Channel);



#endif /* ADC_INTERFACE_H_ */