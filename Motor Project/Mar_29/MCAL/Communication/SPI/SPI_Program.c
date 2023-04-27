/*
 * SPI_Program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#include "SPI_Interface.h"
void SPI_voidInitSPIMaster(void){
	/* Master Initialization */
	SET_BIT(SPCR_Reg,SPCR_MSTR);
	/* Set data mode */
	SET_MODE;
	/* Clock Prescale 16 */
	SET_BIT(SPCR_Reg,SPCR_SPR0);
	CLEAR_BIT(SPCR_Reg,SPCR_SPR1);
	CLEAR_BIT(SPSR_Reg,SPSR_SPI2X);
	/* SPI Enable */
	SET_BIT(SPCR_Reg,SPCR_SPE);
	/* Data order MSB */
	CLEAR_BIT(SPCR_Reg,SPCR_DORD);


}
void SPI_voidSPISlaveInit(void){
	/* Slave Initialization */
	CLEAR_BIT(SPCR_Reg,SPCR_MSTR);
	/* SPI Enable */
	SET_BIT(SPCR_Reg,SPCR_SPE);
	/* Data order MSB */
	CLEAR_BIT(SPCR_Reg,SPCR_DORD);

}
u8 SPI_u8Receive(u8 Copy_u8data){
	SPDR_Reg=Copy_u8data;
	while(GET_BIT(SPSR_Reg,SPSR_SPIF)==0);
	return SPDR_Reg;
}
