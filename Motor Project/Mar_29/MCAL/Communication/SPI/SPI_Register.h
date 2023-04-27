/*
 * SPI_Register.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_
#include "../../DIO/DIO_Interface.h"
#define SPDR_Reg (*(volatile u8*)0x2F)	/* SPI Data Register */

#define SPSR_Reg (*(volatile u8*)0x2E) /* SPI status Register */
#define SPSR_SPIF	7			/* SPI interrupt flag */
#define SPSR_WCOL	6			/* is during data transfer while SPDR written then WCOL and SPIF cleared by first reading*/
#define SPSR_SPI2X	0			/* double speed */

#define SPCR_Reg (*(volatile u8*)0x2D) /* SPI Control register */
#define SPCR_SPIE	7					/* SPI Interrupt Enable */
#define SPCR_SPE	6					/* SPI enable */
#define SPCR_DORD	5					/* Data Order send LSB or MSB first 1,0 */
#define SPCR_MSTR	4					/* Master bit */
#define SPCR_CPOL	3					/* Clock Polarity */
#define SPCR_CPHA	2					/* Clock Phase */
#define SPCR_SPR1	1					/* prescaler bit 1*/
#define SPCR_SPR0	0					/*prescaler bit 0*/
#endif /* MCAL_SPI_SPI_REGISTER_H_ */
