/*
 * Timer_config.h
 *
 * Created: 2/26/2023 10:38:46 AM
 *  Author: amrba
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define NoCLK			0		 // No clock source (Timer/Counter stopped).
#define CLK_NoPS		1		// clkI/O/(No prescaling)
#define CLK_8			2		// clkI/O/8 (From prescaler)
#define CLK_64			3		// clkI/O/64 (From prescaler)
#define CLK_256			4		//clkI/O/256 (From prescaler)
#define CLK_1024		5		// clkI/O/1024 (From prescaler)
#define ExtCLK_Falling  6		//External clock source on T0 pin. Clock on falling edge.
#define ExtCLK_Rising   7		//External clock source on T0 pin. Clock on rising edge.

#define EnableOFInt 0
#define EnableCMPInt 0
/*
			All modes
0	 Normal port operation, OC0 disconnected.,
			Normal Mode			
1	 Toggle OC0 on compare match
			Normal Mode						FastPWM
2	 Clear OC0 on compare , Clear OC0 on compare match and set OC0 at BOTTOM,
			Normal Mode						FastPWM
3	 Set OC0 on compare match , Set OC0 on compare match and clear OC0 at BOTTOM
*/

#define	 CompareMatchOutput	2
#define ClockPrescalerSelect CLK_NoPS
#define CLKFreq	16000000U

/* 0 --> 15  */
#define TIM1ModeNum	14
#define TIM1CLK_PSSelect CLK_256

#endif /* TIMER_CONFIG_H_ */