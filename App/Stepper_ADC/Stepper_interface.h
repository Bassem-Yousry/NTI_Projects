/*
 * Stepper_interface.h
 *
 * Created: 3/5/2023 10:33:24 PM
 *  Author: amrba
 */ 


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef enum {CLKWise,AntiCLKWise}StepperDir;
void Stepper_ADC_init();
void Stepper_ADC_Dir(StepperDir);
void Stepper_ADC_Speed(u16);
void Stepper_ADC_Start();


#endif /* STEPPER_INTERFACE_H_ */