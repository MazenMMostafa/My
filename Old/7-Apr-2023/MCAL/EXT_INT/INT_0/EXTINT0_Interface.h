/*
 * EXTINT0_Interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_0_EXTINT0_INTERFACE_H_
#define MCAL_EXT_INT_INT_0_EXTINT0_INTERFACE_H_
#include "EXTINT0_Config.h"
#include "../Global_Interrupt_Enable.h"
void INT0_VoidSETINT0(void);
INT0_Err INT0_SetCallBack(void (*INT0CB)(void));
#endif /* MCAL_EXT_INT_INT_0_EXTINT0_INTERFACE_H_ */
