/*
 * Keybad_prog.c
 *
 * Created: 2/17/2023 2:47:58 PM
 *  Author: amrba
 */ 
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"
#define F_CPU 16000000
#include "util/delay.h"
/* assume this is our keypad */
static const u8 KepadArray[4][4]={
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','0','*'},
	{'(','=',')','/'}
};
	

void Keypad_init(){
		DIO_SetPinDir(Column1,INPUT);
		DIO_SetPinDir(Column2,INPUT);
		DIO_SetPinDir(Column3,INPUT);
		DIO_SetPinDir(Column4,INPUT);
		
		DIO_SetPinDir(Row1,OUTPUT);
		DIO_SetPinDir(Row2,OUTPUT);
		DIO_SetPinDir(Row3,OUTPUT);
		DIO_SetPinDir(Row4,OUTPUT);
		
		DIO_SetPinValue(Row1,HIGH);
		DIO_SetPinValue(Row2,HIGH);
		DIO_SetPinValue(Row3,HIGH);
		DIO_SetPinValue(Row4,HIGH);
}
u8 Keypad_GetCol(){
	if (DIO_GetPinValue(Column1)==0)
	{
		_delay_ms(10);
		while (DIO_GetPinValue(Column1)==0);	
		return 1;
	}
	
	else if (DIO_GetPinValue(Column2)==0)
	{
		_delay_ms(10);
		while (DIO_GetPinValue(Column2)==0);
		return 2;
	}
	else if (DIO_GetPinValue(Column3)==0)
	{
		_delay_ms(10);
		while (DIO_GetPinValue(Column3)==0);
		return 3;
	}
	else if (DIO_GetPinValue(Column4)==0)
	{
		_delay_ms(10);
		while (DIO_GetPinValue(Column4)==0);
		//while (DIO_GetPinValue(Column4)==1);	
		return  4;
	}
	return 0;
}
u8 Keypad_GetKey(){
	u8 kepad_col;
	for (int i=0;i<4;i++)
	{
		DIO_TogPinValue(DIO_PORTC,PIN5-i);
		kepad_col=Keypad_GetCol();
		if (kepad_col!=0)
		{
			DIO_TogPinValue(DIO_PORTC,PIN5-i);
			return (KepadArray[i][kepad_col-1]);
		}
		DIO_TogPinValue(DIO_PORTC,PIN5-i);
	}
	return 0;
}

