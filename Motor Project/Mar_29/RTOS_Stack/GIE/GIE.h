/*
 * Global_Interrupt_Enable.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_GLOBAL_INTERRUPT_ENABLE_H_
#define MCAL_EXT_INT_GLOBAL_INTERRUPT_ENABLE_H_
#include "../../common/Common_H.h"

#define SREG_Reg  (*(volatile u8*)0x5F)
#define SREG_GobalInterrupt_BIT 7
#define ENABLEINT0_SREG SET_BIT(SREG_Reg,SREG_GobalInterrupt_BIT)

void GIEEnable(void);
#endif /* MCAL_EXT_INT_GLOBAL_INTERRUPT_ENABLE_H_ */
