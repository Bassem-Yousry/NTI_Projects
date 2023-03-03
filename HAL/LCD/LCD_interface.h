/*
 * Keypad_interface.h
 *
 * Created: 2/17/2023 2:49:02 PM
 *  Author: amrba
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include <stdlib.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#define F_CPU 16000000
#include "util/delay.h"

void LCD_init();
void LCD_SendCMD(u8 Copy_u8CMD);
void LCD_SendData(u8 Copy_u8Data);
void LCD_DisplayString(char * str);
void LCD_goto(u8 row,u8 col);
void LCD_WriteNUM(s64 NUM);
void LCD_WriteFLOAT(f64 num,u8 Percision);
void LCD_ClearDisplay();


#endif /* KEYPAD_INTERFACE_H_ */