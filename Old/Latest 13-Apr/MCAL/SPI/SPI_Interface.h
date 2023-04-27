/*
 * SPI_Interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "SPI_Register.h"
void SPI_voidInitSPIMaster(void);
u8 SPI_u8SendReceive(u8 data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
