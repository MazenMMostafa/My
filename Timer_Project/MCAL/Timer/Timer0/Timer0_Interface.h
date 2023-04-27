/*
 * Timer0_Interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_

#include "Timer0_Config.h"
void T0_VoidInit(void);
u8 Timer0_u8SetCallBack(void (*Copy_pvCallBackfun)(void));
#endif /* MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_ */
