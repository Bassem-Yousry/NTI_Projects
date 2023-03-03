/*
 * ADC_private.h
 *
 * Created: 2/25/2023 9:25:07 AM
 *  Author: amrba
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define  ADCDATA *((volatile u16*)0x24)
#define SFIOR	 *((volatile u8*)0x50)
#define ACSR	 *((volatile u8*)0x28) 
#define ADMUX	 *((volatile u8*)0x27) 
#define ADCSRA	 *((volatile u8*)0x26) 





#endif /* ADC_PRIVATE_H_ */