/*
 * Common_INT_Reg.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_COMMON_INT_REG_H_
#define MCAL_EXT_INT_COMMON_INT_REG_H_

#define MCUCSR_Reg (*(volatile u8*)0x54)
#define MCUCR_Reg (*(volatile u8*)0x55)
#define GICR_Reg (*(volatile u8*)0x5B)
#define GIFR_Reg (*(volatile u8*)0x5A)


#endif /* MCAL_EXT_INT_COMMON_INT_REG_H_ */
