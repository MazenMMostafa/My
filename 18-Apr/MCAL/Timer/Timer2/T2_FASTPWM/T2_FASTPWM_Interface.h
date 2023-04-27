/*
 * Timer0_Interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_FASTPWM_INTERFACE_H_
#define MCAL_TIMER_TIMER2_TIMER2_FASTPWM_INTERFACE_H_
#include "T2_FASTPWM_Config.h"
void T2_VoidFPWMInit(void);
void T2_VoidSetCallbackFPWM(void (*T2Copy_CallBack)(void));
void T2_VoidSetOCR2(u8 OCR);
#endif /* MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_ */
