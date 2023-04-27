/*
 * EXTINT2_Interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_2_EXTINT2_INTERFACE_H_
#define MCAL_EXT_INT_INT_2_EXTINT2_INTERFACE_H_
#include "../Global_Interrupt_Enable.h"
#include "EXTINT2_Config.h"
void INT2_VoidSETINT2(void);
INT2_Err INT2_SetCallBack(void (*INT2CB)(void));


#endif /* MCAL_EXT_INT_INT_2_EXTINT2_INTERFACE_H_ */
