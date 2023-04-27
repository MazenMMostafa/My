/*
 * Timer0_Interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_
void Time_0_Init(void);
void __vector_11 (void)  __attribute__((signal));
//void (*VoidNormalTimer0)(void) =Null;
//void CallBackTimer0(void(*Timer0)(void));
#endif /* MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_ */
