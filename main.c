/*
* NTI.c
*
* Created: 2/17/2023 9:41:52 AM
* Author : amrba
*/

#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/Keypad/Keypad_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "App/Calc/calc_interface.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MCAL/EX_INT/EX_INT_Interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/Timer/Timer_interface.h"
#include "App/DC_Motor_ADC/DC_ADC_interface.h"
#include <stdio.h>
#define RED DIO_PORTB,PIN7
#define Green DIO_PORTA,PIN4
#define BLUE DIO_PORTA,PIN5
#define Yellow DIO_PORTA,PIN6

int main(void)
{
Servo_ADC_init();	
Servo_ADC_start();
//DC_ADC_init();
//DC_ADC_start();

}

