/*
 * Keypad_config.h
 *
 * Created: 2/18/2023 10:12:39 AM
 *  Author: amrba
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/* Input */
#define Column1 DIO_PORTD,PIN7
#define Column2 DIO_PORTD,PIN6
#define Column3 DIO_PORTD,PIN5
#define Column4 DIO_PORTD,PIN3
/*output*/
#define Row1 DIO_PORTC,PIN5
#define Row2 DIO_PORTC,PIN4
#define Row3 DIO_PORTC,PIN3
#define Row4 DIO_PORTC,PIN2

#endif /* KEYPAD_CONFIG_H_ */