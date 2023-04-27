/*
 * SPI_Interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "SPI_Config.h"
void SPI_voidSPIMasterInit(void);
void SPI_voidSPISlaveInit(void);
u8 SPI_u8Receive(u8 Copy_u8data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
