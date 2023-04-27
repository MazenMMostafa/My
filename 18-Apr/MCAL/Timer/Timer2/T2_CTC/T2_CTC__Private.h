/*
 * Timer0_Private.h
 *	T0_CTC
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_CTC_PRIVATE_H_
#define MCAL_TIMER_TIMER2_TIMER2_CTC_PRIVATE_H_
#include "T2_CTC_Register.h"

				/* TCCR2 Bits */
#define TCCR2_FOC2 7 /* This bit is set to 1 for non pwm (ctc) and 0 for pwm */
/* WGM to choose mode  WGM21 -> 1  WGM20 -> 0 CTC Mode*/
#define TCCR2_WGM20 6
#define TCCR2_WGM21 3
/*
COM21  COM20 Description
  0   	0    Normal port operation, OC2 disconnected.
  0   	1    Toggle OC2 on compare match
  1   	0    Clear OC2 on compare match
  1   	1    Set OC2 on compare match
  */
#define TCCR2_COM21 5
#define TCCR2_COM20 4
/* Prescalers */
#define TCCR2_CS22 2
#define TCCR2_CS21 1
#define TCCR2_CS20 0

				/* TIMSK Bits */
#define TIMSK_OCIE2 7 /* CTC Interrupt enable */
#define TIMSK_TOIE2 6 /*overflow Flag enable */

#endif /* MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_ */
