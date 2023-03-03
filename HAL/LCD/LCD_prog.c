/*
 * Keybad_prog.c
 *
 * Created: 2/17/2023 2:47:58 PM
 *  Author: amrba
 */ 

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_interface.h"
#include "LCD_Config.h"
#include "LCD_private.h"
#include "../../BIT_MATH.h"
u8 LCD_DataPinArary[4]={LCD_D4,LCD_D5,LCD_D6,LCD_D7};

static const u8 LCD_LineAddress[4]={LCD_Line1_1stAddress,LCD_Line2_1stAddress,LCD_Line3_1stAddress,LCD_Line4_1stAddress};
static void LCD_4BitMode_SetData(u8 Copy_u8Data){
for (int i =0;i<4;i++)
{
	DIO_SetPinValue(LCD_DataPort,LCD_DataPinArary[i],GET_BIT(Copy_u8Data,i));
}
}


void LCD_goto(u8 row,u8 col){
	
	LCD_SendCMD(LCD_LineAddress[row]+col);
}

void LCD_WriteNUM(s64 NUM){
	char num[10];
	itoa(NUM,num,10);
	LCD_DisplayString(num);
}
void LCD_WriteFLOAT(f64 num,u8 Percision){
	LCD_WriteNUM(num); //send Int Part
	LCD_SendData('.');
	num -=(s64)num;
	for(int i=0;i<Percision;i++){ //move the decimal point
		num*=10;
	}
	LCD_WriteNUM((s64)num);//send fractional part
}
void LCD_init(){
	_delay_ms(450);
	DIO_SetPinDir(LCD_Enable,OUTPUT);
	DIO_SetPinValue(LCD_Enable,LOW);
	
	DIO_SetPinDir(LCD_RS,OUTPUT);
	
	DIO_SetPinDir(LCD_DataPort,LCD_D4,OUTPUT);
	DIO_SetPinDir(LCD_DataPort,LCD_D5,OUTPUT);
	DIO_SetPinDir(LCD_DataPort,LCD_D6,OUTPUT);
	DIO_SetPinDir(LCD_DataPort,LCD_D7,OUTPUT);
	
	LCD_SendCMD(0x3);
	_delay_ms(5);
	LCD_SendCMD(0x3);
	_delay_ms(5);
	LCD_SendCMD(0x3);
	_delay_ms(1);
	LCD_SendCMD(CMD_Return_Home);
		_delay_ms(5);
	LCD_SendCMD(CMD_LCD_4Bit_Mode_2_Line_5X8);
		_delay_ms(5);
	LCD_SendCMD(CMD_Clear_Display);
		_delay_ms(5);
	LCD_SendCMD(CMD_Display_Cursor_Blink_ALL_ON);
		_delay_ms(5);
	LCD_SendCMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(5);
}
void LCD_SendCMD(u8 Copy_u8CMD){
	/* send upper nibble */
	DIO_SetPinValue(LCD_RS,LOW);	
	DIO_SetPinValue(LCD_Enable,HIGH);
	LCD_4BitMode_SetData((Copy_u8CMD>>4)&0x0f);
	DIO_SetPinValue(LCD_Enable,LOW);
	_delay_ms(5);
		/* send lower nibble */
		DIO_SetPinValue(LCD_RS,LOW);
		DIO_SetPinValue(LCD_Enable,HIGH);
		LCD_4BitMode_SetData((Copy_u8CMD)&0x0f);
		DIO_SetPinValue(LCD_Enable,LOW);
		
}
void LCD_SendData(u8 Copy_u8Data){
	/* send upper nibble */
	DIO_SetPinValue(LCD_RS,HIGH);
	DIO_SetPinValue(LCD_Enable,HIGH);
	LCD_4BitMode_SetData((Copy_u8Data>>4)&0x0f);
	DIO_SetPinValue(LCD_Enable,LOW);
	_delay_ms(5);
	/* send lower nibble */
	DIO_SetPinValue(LCD_RS,HIGH);
	DIO_SetPinValue(LCD_Enable,HIGH);
	LCD_4BitMode_SetData((Copy_u8Data)&0x0f);
	DIO_SetPinValue(LCD_Enable,LOW);
}
void LCD_DisplayString(char * str){
	for(;*str;str++){
		LCD_SendData(*str);
		_delay_ms(5);
	}
}
void LCD_ClearDisplay(){
	LCD_SendCMD(CMD_Clear_Display);
}
