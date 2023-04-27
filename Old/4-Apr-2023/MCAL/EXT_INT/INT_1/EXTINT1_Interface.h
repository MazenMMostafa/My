/*
 * EXTINT1_Interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_1_EXTINT1_INTERFACE_H_
#define MCAL_EXT_INT_INT_1_EXTINT1_INTERFACE_H_

#include "EXTINT1_Config.h"
#include "../Global_Interrupt_Enable.h"
void INT1_VoidSETINT1(void);
INT1_Err INT1_SetCallBack(void (*INT1CB)(void));

#endif /* MCAL_EXT_INT_INT_1_EXTINT1_INTERFACE_H_ */
