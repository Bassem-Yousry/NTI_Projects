/*
* GPIO.c
*
* Created: 1/9/2023 3:39:41 PM
*  Author: amrba
*/
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_config.h"

void DIO_SetPinDir(PORT_TYPE Copy_enmPortNum,PIN_TYPE Copy_enmPinNum,MODE_TYPE Copy_enmMode){
	/*	Function skeleton
	1-check Port number first
	2-Then check Direction (Input or Output)
	3-set Pin direction through DDR
	*/
	if (Copy_enmPinNum>PIN7)
	{
		return;		
	}
	switch(Copy_enmPortNum){
		case DIO_PORTA:
		if (Copy_enmMode==INPUT)
		{
			CLR_BIT(DDRA,Copy_enmPinNum);
		}else if (Copy_enmMode==OUTPUT)
		{
			SET_BIT(DDRA,Copy_enmPinNum);
		}
		break;
		case DIO_PORTB:
		if (Copy_enmMode==INPUT)
		{
			CLR_BIT(DDRB,Copy_enmPinNum);
		}else if (Copy_enmMode==OUTPUT)
		{
			SET_BIT(DDRB,Copy_enmPinNum);
		}
		break;
		case DIO_PORTC:
		if (Copy_enmMode==INPUT)
		{
			CLR_BIT(DDRC,Copy_enmPinNum);
		}else if (Copy_enmMode==OUTPUT)
		{
			SET_BIT(DDRC,Copy_enmPinNum);
		}
		break;
		case DIO_PORTD:
		if (Copy_enmMode==INPUT)
		{
			CLR_BIT(DDRD,Copy_enmPinNum);
		}else if (Copy_enmMode==OUTPUT)
		{
			SET_BIT(DDRD,Copy_enmPinNum);
		}
		break;
		default:break;
		
	}


}

void DIO_SetPinValue(PORT_TYPE Copy_enmPortNum,PIN_TYPE Copy_enmPinNum,MODE_TYPE Copy_enmMode){
	/*	Function skeleton
	1-check Port number first
	2-Then check Pin Mode (LOW/HIGH)
	3-set Pin Value through PORTX
	*/
	switch(Copy_enmPortNum){
		case DIO_PORTA:
		if (Copy_enmMode==LOW)
		{
			CLR_BIT(PORTA,Copy_enmPinNum);
		}else if (Copy_enmMode==HIGH)
		{
			SET_BIT(PORTA,Copy_enmPinNum);
		}
		break;
		case DIO_PORTB:
		if (Copy_enmMode==LOW)
		{
			CLR_BIT(PORTB,Copy_enmPinNum);
		}else if (Copy_enmMode==HIGH)
		{
			SET_BIT(PORTB,Copy_enmPinNum);
		}
		break;
		case DIO_PORTC:
		if (Copy_enmMode==LOW)
		{
			CLR_BIT(PORTC,Copy_enmPinNum);
		}else if (Copy_enmMode==HIGH)
		{
			SET_BIT(PORTC,Copy_enmPinNum);
		}
		break;
		case DIO_PORTD:
		if (Copy_enmMode==LOW)
		{
			CLR_BIT(PORTD,Copy_enmPinNum);
		}else if (Copy_enmMode==HIGH)
		{
			SET_BIT(PORTD,Copy_enmPinNum);
		}
		break;
		default:break;

	}
}

void DIO_SetPortValue(PORT_TYPE Copy_enmPortNum,u8 Copy_u8Data){
	
	switch(Copy_enmPortNum){
		case DIO_PORTA:PORTA=Copy_u8Data;
		break;
		case DIO_PORTB:PORTB=Copy_u8Data;
		break;
		case DIO_PORTC:PORTC=Copy_u8Data;
		break;
		case  DIO_PORTD:PORTD=Copy_u8Data;
		break;
		default:break;
	}
}


u8   DIO_GetPinValue(PORT_TYPE Copy_enmPortNum,PIN_TYPE Copy_enmPinNum){
	/*	Function skeleton
	1-check Port number first
	2-Return Pin value through PORTx
	*/
	switch(Copy_enmPortNum){
		case DIO_PORTA:
		return GET_BIT(PINA,Copy_enmPinNum);
		break;
		case DIO_PORTB:
		return		GET_BIT(PINB,Copy_enmPinNum);

		break;
		return GET_BIT(PINC,Copy_enmPinNum);
		break;
		case DIO_PORTD:
		return GET_BIT(PIND,Copy_enmPinNum);
		break;
		default:break;
		
		
	}
	return 0;
}
void DIO_TogPinValue(PORT_TYPE Copy_enmPortNum,PIN_TYPE Copy_enmPinNum){
	/*	Function skeleton
	1-check Port number first
	2-Tog Pin Value through PORTx
	*/
	switch(Copy_enmPortNum){
		case DIO_PORTA:
		 TOG_BIT(PORTA,Copy_enmPinNum);
		break;
		case DIO_PORTB:
				TOG_BIT(PORTB,Copy_enmPinNum);

		break;
		case DIO_PORTC:
		TOG_BIT(PORTC,Copy_enmPinNum);
		break;
		case DIO_PORTD:
		TOG_BIT(PORTD,Copy_enmPinNum);
		break;
		default:break;
	}
}

void DIO_SetInputPullup(PORT_TYPE Copy_enmPortNum,PIN_TYPE Copy_enmPinNum){
	/*	Function skeleton
	1-clear PUD pin in SFIOR Reg
	2-set  Direction to Input
	3-set Pin value through PORTx
	*/
	DIO_SetPinDir(Copy_enmPortNum, Copy_enmPinNum,INPUT);
	DIO_SetPinValue(Copy_enmPortNum, Copy_enmPinNum,HIGH);
}



