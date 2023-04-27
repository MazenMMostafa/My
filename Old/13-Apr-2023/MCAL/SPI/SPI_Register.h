/*
 * SPI_Register.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_
#include "SPI_Private.h"
#define SPDR_Reg (*(volatile u8*)0x2F)
#define SPSR_Reg (*(volatile u8*)0x2E)
#define SPCR_Reg (*(volatile u8*)0x2D)

#endif /* MCAL_SPI_SPI_REGISTER_H_ */
