/*
 * SPI_Program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */
#include "../DIO/DIO_Interface.h"
#include "SPI_Interface.h"
void SPI_voidInitSPIMaster(void){
	DIO_ErrStateSetPinDirection(PORT_B,PIN_5,DIO_OUT);
	DIO_ErrStateSetPinDirection(PORT_B,PIN_6,DIO_IN);
	DIO_ErrStateSetPinDirection(PORT_B,PIN_7,DIO_OUT);
	/* Slave Select Pin */
	DIO_ErrStateSetPinDirection(PORT_A,PIN_7,DIO_OUT);
	/* Prescaler 16  */
	SET_BIT(SPCR_Reg,0);
	/* CPH */
	SET_BIT(SPCR_Reg,2);
	/* CPOL */
	SET_BIT(SPCR_Reg,3);
	/* Master Select */
	SET_BIT(SPCR_Reg,4);
	/* LSB */
	SET_BIT(SPCR_Reg,5);
	/* SPI Enable */
	SET_BIT(SPCR_Reg,6);

}
u8 SPI_u8SendReceive(u8 data){

	DIO_ErrStateSetPinValue(PORT_A,PIN_7,DIO_LOW);
	SPDR_Reg=data;
	while(GET_BIT(SPSR_Reg,7)==0);
	//DIO_ErrStateSetPinValue(PORT_A,PIN_7,DIO_HIGH);
	return SPDR_Reg;
}
