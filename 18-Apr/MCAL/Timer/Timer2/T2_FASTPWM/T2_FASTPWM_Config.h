/*
 * T2_FASTPWM_Config.h
 *
 *  Created on: Apr 15, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER2_T2_FASTPWM_T2_FASTPWM_CONFIG_H_
#define MCAL_TIMER_TIMER2_T2_FASTPWM_T2_FASTPWM_CONFIG_H_
#include "T2_FASTPWM_Private.h"
#define div0	0
#define div8	1
#define div32	2
#define div64	3
#define div128	4
#define div256	5
#define div1024	6

#define Prescale div16

#if Prescale==div0

	#define Set_Prescaler SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
						  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
						  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div8
	#define Set_Prescaler CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
						  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
						  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div32
#define Set_Prescaler SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
					  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div64
#define Set_Prescaler CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
					  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div128
#define Set_Prescaler SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
					  CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div256
#define Set_Prescaler CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#elif Prescale==div1024
#define Set_Prescaler SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS20);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS21);\
					  SET_BIT(TCCR2_Reg,TCCR2_FPWM_CS22)
#endif
#endif /* MCAL_TIMER_TIMER2_T2_FASTPWM_T2_FASTPWM_CONFIG_H_ */
