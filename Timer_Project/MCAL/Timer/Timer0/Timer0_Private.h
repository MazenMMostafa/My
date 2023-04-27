/*
 * Timer0_Private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_
#include "Timer0_Register.h"
#define F_CPU 8000000

/* T0 Modes */
#define T0_Normal 1
#define T0_PWM 2
#define T0_PhaseCorrect 3
#define T0_CTC 4
#define T0_FastPWM 5

/* Prescale Timer0 */
#define T0_NO_CLOCK 1
#define T0_NO_Presc 2
#define T0_Presc_8 8
#define T0_Presc_64 64
#define T0_Presc_256 256
#define T0_Presc_1024 1024
#define T0_External_Fal 7
#define T0_External_Ris 8

#define T0_PSR10 0
/* ------ TCCR0 ----- */
/* Force output compare Timer0 */
#define TCCR0_FOC0 7 /* its being active in non pwm but for using pwm mode should write it as 0 */
#define TCCR0_WGM00 6 /* Wave From genartion mode WGM00 WGM01 for choosing timer mode P80 */
#define TCCR0_WGM01 3
#define TCCR0_COM01 5 /* COM00 COM01 for compare output mode  Normal port ,toggle, clear,set */
#define TCCR0_COM00 4
#define TCCR0_CS00 0 /* CS for Clock Select */
#define TCCR0_CS01 1
#define TCCR0_CS02 2
/* ----- TIMSK ----- */
#define TIMSK_TOIE0 0 /* Overflow Interrupt Enable */
#define TIMSK_OCIE0 1 /* output compare match interrupt enable */
/* ---- TIFR ---- */
#define TIFR_OCF0 1 /* output Compare flag */
#define TIFR_TOV0 0 /* overflow flag */
#endif /* MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_ */
