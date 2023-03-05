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
#define TIFR   *((volatile u8*)0x58) 

#define TCCR1A   *((volatile u8*)0x4F) // COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107
#define TCCR1B   *((volatile u8*)0x4E) // ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 110
#define TCNT1H   *((volatile u8*)0x4D) // Timer/Counter1 – Counter Register High Byte 111
#define TCNT1L   *((volatile u8*)0x4C) // Timer/Counter1 – Counter Register Low Byte 111
#define OCR1AL   *((volatile u16*)0x4A) // Timer/Counter1 – Output Compare Register A Low Byte 111
#define OCR1BH   *((volatile u8*)0x49) // Timer/Counter1 – Output Compare Register B High Byte 111
#define OCR1BL   *((volatile u16*)0x48) // Timer/Counter1 – Output Compare Register B Low Byte 111
#define ICR1L    *((volatile u16*)0x46) //Tim


#endif /* TIMER_PRIVATE_H_ */