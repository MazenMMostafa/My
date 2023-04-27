/*
 * EXTINT2_Config.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_2_EXTINT2_CONFIG_H_
#define MCAL_EXT_INT_INT_2_EXTINT2_CONFIG_H_
#include "EXTINT2_Private.h"
#include "../Common_INT_Reg.h"
#define ENABLEINT2_FALLING_EDGE SET_BIT(MCUCSR_Reg,ISC2)
#define ENABLEINT2_GICR_Reg SET_BIT(GICR_Reg,GICR_INT2_BIT)
#endif /* MCAL_EXT_INT_INT_2_EXTINT2_CONFIG_H_ */
