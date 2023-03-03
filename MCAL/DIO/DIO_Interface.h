/*
 * GPIO.h
 *
 * Created: 1/9/2023 3:25:06 PM
 *  Author:bassem
 */ 


#ifndef DIO_Interface_H_
#define DIO_Interface_H_
#include "../../STD_TYPES.h"

typedef enum{DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD}PORT_TYPE;
typedef enum{LOW,HIGH,INPUT,OUTPUT}MODE_TYPE;
typedef enum{PIN0=0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7}PIN_TYPE;
	
void DIO_SetPinDir(PORT_TYPE,PIN_TYPE,MODE_TYPE);	
void DIO_SetPinValue(PORT_TYPE,PIN_TYPE,MODE_TYPE);	

void DIO_SetPortValue(PORT_TYPE,u8 Copy_u8Data);

u8   DIO_GetPinValue(PORT_TYPE,PIN_TYPE);	
void DIO_SetInputPullup(PORT_TYPE,PIN_TYPE);	
void DIO_TogPinValue(PORT_TYPE,PIN_TYPE);	

#endif