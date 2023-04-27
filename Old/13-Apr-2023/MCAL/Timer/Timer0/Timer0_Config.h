/*
 * Timer0_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_
#include "Timer0_Private.h"
#define T0_Type T0_CTC
/* Desired Time to count */
#define DesiredTime 1000
/* OCR0 needs based on the maximum number made of 8 bit and less than desiredtime that need to be counted */
#define BasedonTimerbits 250
/* 1000 Microsecond  */
#define T0_SetPrescaler T0_Presc_8
/// Tick Time = Presc/SysFreq
//CTC by3ml clear lel time 3nd w2t el OCR0 el bt7ddo
/*
 * Steps :
 * 1- Tick time=Presc/SysFreq
 * 2- shof lw el tick time bysawy el w2t el enta 3yzo wla la2
 * 3- lw la2 bn5tar rkm y2bl el esma 3la el time el enta 3yzo
 * example lw enta msln 1000000 us momken n5tar OCR0=250
 * yb2a kda el htcount 4000 mra yb2a 1 sec up
 *
 */
/*  Prescaler  */
#if T0_SetPrescaler == T0_Presc_8
#define Prescale CLEAR_BIT(TCCR0_Reg,TCCR0_CS00);\
		SET_BIT(TCCR0_Reg,TCCR0_CS01);\
		CLEAR_BIT(TCCR0_Reg,TCCR0_CS02)

#elif T0_SetPrescaler == T0_Presc_64
#define Prescale SET_BIT(TCCR0_Reg,TCCR0_CS00);\
		SET_BIT(TCCR0_Reg,TCCR0_CS01);\
		CLEAR_BIT(TCCR0_Reg,TCCR0_CS02)


#elif T0_SetPrescaler == T0_Presc_256
#define Prescale CLEAR_BIT(TCCR0_Reg,TCCR0_CS00);\
		CLEAR_BIT(TCCR0_Reg,TCCR0_CS01);\
		SET_BIT(TCCR0_Reg,TCCR0_CS)

#elif T0_SetPrescaler == T0_Presc_1024
#define Prescale SET_BIT(TCCR0_Reg,TCCR0_CS00);\
		CLEAR_BIT(TCCR0_Reg,TCCR0_CS01);\
		SET_BIT(TCCR0_Reg,TCCR0_CS)

#endif
//-----------------------------//
/* Fast PWM */
#define T0_FPWM T0_FPWM_CLRTOP
#if T0_FPWM == T0_FPWM_CLRTOP
#define SetFPWMType SET_BIT(TCCR0_Reg,TCCR0_COM00);\
					SET_BIT(TCCR0_Reg,TCCR0_COM01)
#elif T0_FPWM == T0_FPWM_CLRCTC
#define SetFPWMType CLEAR_BIT(TCCR0_Reg,TCCR0_COM00);\
					SET_BIT(TCCR0_Reg,TCCR0_COM01)
#endif
#endif /* MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_ */
