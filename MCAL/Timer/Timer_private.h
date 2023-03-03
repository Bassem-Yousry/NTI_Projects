/*
 * Timer_private.h
 *
 * Created: 2/26/2023 10:38:02 AM
 *  Author: amrba
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0  *((volatile u8*)0x53)
#define TCNT0  *((volatile u8*)0x52)
#define OCR0   *((volatile u8*)0x5c)
#define TIMSK  *((volatile u8*)0x59) 
#define TIFR	*((volatile u8*)0x58) 
#endif /* TIMER_PRIVATE_H_ */