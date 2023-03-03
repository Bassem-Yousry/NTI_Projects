/*
 * LCD_Config.h
 *
 * Created: 2/18/2023 11:41:00 AM
 *  Author: amrba
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DataPort DIO_PORTB

#define LCD_D4 PIN0
#define LCD_D5 PIN1
#define LCD_D6 PIN2
#define LCD_D7 PIN4

#define LCD_Enable DIO_PORTA,PIN2
#define LCD_RS DIO_PORTA,PIN3


#endif /* LCD_CONFIG_H_ */