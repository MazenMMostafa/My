/*
 * UART_Register.h
 *
 *  Created on: Apr 7, 2023
 *      Author: Mazen
 */

#ifndef MCAL_UART_UART_REGISTER_H_
#define MCAL_UART_UART_REGISTER_H_
#include "../../DIO/DIO_Interface.h"
#define   UDR_Reg (*(volatile u8*)0x2C)
#define UCSRA_Reg (*(volatile u8*)0x2B)
#define UCSRB_Reg (*(volatile u8*)0x2A)
#define UCSRC_Reg (*(volatile u8*)0x40)
#define UBRRH_Reg (*(volatile u8*)0x40)
#define UBRRL_Reg (*(volatile u8*)0x29)



#endif /* MCAL_UART_UART_REGISTER_H_ */
