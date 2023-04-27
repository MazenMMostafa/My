/*
 * UART_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Mazen
 */

#include "UART_Interface.h"

void UART_VoidInit(void){
	/* Set Baud Rate */
	UBRRH_Reg=51;
	u8 UCSRC_VAR;
	/* Selecting UCSRC Register */
	SET_BIT(UCSRC_VAR,URSEL);
	/*  No Interrupt on Receive */
	CLEAR_BIT(UCSRB_Reg,RXCIE);
	/*  No Interrupt on Transmit */
	CLEAR_BIT(UCSRB_Reg,TXCIE);
	/* Enable Asynchronous */
	CLEAR_BIT(UCSRC_VAR,UMSEL);
	/* Parity Mode */
	CLEAR_BIT(UCSRC_VAR,UPM0);
	CLEAR_BIT(UCSRC_VAR,UPM1);
	/* 1 Stop Bit */
	CLEAR_BIT(UCSRC_VAR,USBS);
	/* Data Bits */
	SET_BIT(UCSRC_VAR,UCSZ0);
	SET_BIT(UCSRC_VAR,UCSZ1);
	CLEAR_BIT(UCSRC_VAR,UCSZ2);
	/* Set the Value in Register */
	UCSRC_Reg=UCSRC_VAR;
	/* Enable Transmit */
	SET_BIT(UCSRB_Reg,TXEN);
	/* Enable Receive */
	SET_BIT(UCSRB_Reg,RXEN);
}
void UART_VoidSend(u16 Data){
	/* Wait until transmit finish */
	while( !(UCSRA_Reg&(1<<UDRE)));
	UDR_Reg=Data;

}
