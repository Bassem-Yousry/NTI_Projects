/*
 * EX_INT_Interface.h
 *
 * Created: 2/24/2023 9:50:06 AM
 *  Author: amrba
 */ 


#ifndef EX_INT_INTERFACE_H_
#define EX_INT_INTERFACE_H_

typedef enum{
	IRQ_AT_ANY_LOGIC_CHANGE ,
	IRQ_AT_FALLING_EDGE ,
	IRQ_AT_RISING_EDGE ,
	NO_IRQ
	}IRQ_Type;

typedef enum{
	INT2_PIN,
	INT1_PIN,
	INT0_PIN,
}INT_PIN;



void GIE();
void GID();

void EX_INT_SET_MODE(INT_PIN, IRQ_Type);
void EX_INT_SET_Handler(INT_PIN PinNum, void(*Handler)());



#endif /* EX_INT_INTERFACE_H_ */