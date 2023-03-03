/*
 * EX_INT_prog.c
 *
 * Created: 2/24/2023 9:51:00 AM
 *  Author: amrba
 */ 
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "avr/interrupt.h"
#include "EX_INT_config.h"
#include "EX_INT_Interface.h"
#include "EX_INT_Private.h"

void GIE(){
	asm ("SEI");
}
void GID(){
	asm("CLI");
}

//int(*e)(void)=(void*)0;

static void (*INT0Handler)(void);
static void (*INT1Handler)();
static void (*INT2Handler)();
void EX_INT_SET_Handler(INT_PIN PinNum, void(*Handler)()){
	switch(PinNum){
		case INT0_PIN:
		INT0Handler=Handler;
		break;
		case INT1_PIN:
		//INT1Handler=Handler;
		break;
		case INT2_PIN:
		//INT2Handler=Handler;
		break;
		default:break;
	}
}
void EX_INT_SET_MODE(INT_PIN PinNum, IRQ_Type IRQ_Mode){
	
	switch(PinNum){
		case INT0_PIN:
		if (IRQ_Mode==IRQ_AT_FALLING_EDGE)
		{
			SET_BIT(GICReg,6);
			SET_BIT(MCUCReg,1);
			CLR_BIT(MCUCReg,0);
		} 
		else if(IRQ_Mode==IRQ_AT_RISING_EDGE)
		{
			SET_BIT(GICReg,6);
			SET_BIT(MCUCReg,1);
			SET_BIT(MCUCReg,0);
			
		}
		else if (IRQ_Mode==IRQ_AT_ANY_LOGIC_CHANGE)
		{
			SET_BIT(GICReg,6);
			CLR_BIT(MCUCReg,1);
			SET_BIT(MCUCReg,0);
		}
		else if (IRQ_Mode==NO_IRQ)
		{
			CLR_BIT(GICReg,6);
		}
		break;
		case INT1_PIN:
		if (IRQ_Mode==IRQ_AT_FALLING_EDGE)
		{
			SET_BIT(GICReg,7);
			SET_BIT(MCUCReg,3);
			CLR_BIT(MCUCReg,2);
		}
		else if(IRQ_Mode==IRQ_AT_RISING_EDGE)
		{
			SET_BIT(GICReg,7);
			SET_BIT(MCUCReg,3);
			SET_BIT(MCUCReg,2);
			
		}
		else if (IRQ_Mode==IRQ_AT_ANY_LOGIC_CHANGE)
		{
			SET_BIT(GICReg,7);
			CLR_BIT(MCUCReg,3);
			SET_BIT(MCUCReg,2);
		}
		else if (IRQ_Mode==NO_IRQ)
		{
			CLR_BIT(GICReg,7);
		}
		break;
		case INT2_PIN:	
		if (IRQ_Mode==IRQ_AT_FALLING_EDGE)
		{
			SET_BIT(GICReg,5);
			CLR_BIT(MCUCSReg,6);
		}
		else if(IRQ_Mode==IRQ_AT_RISING_EDGE)
		{
			SET_BIT(GICReg,5);
			SET_BIT(MCUCSReg,6);
		}
		else if (IRQ_Mode==IRQ_AT_ANY_LOGIC_CHANGE)
		{
			//Not Allowed
		}
		else if (IRQ_Mode==NO_IRQ)
		{
			CLR_BIT(GICReg,5);
		}
		break;	
	}
}


ISR (INT0_vect) {	
	INT0Handler();
	
}
ISR (INT1_vect) {
	INT1Handler();
}
ISR (INT2_vect) {
	INT2Handler();
}
