/*
 * UART_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Mazen
 */

#ifndef MCAL_COMMUNICATION_UART_UART_INTERFACE_H_
#define MCAL_COMMUNICATION_UART_UART_INTERFACE_H_
#include "UART_Register.h"
#include "UART_Private.h"
#include "../../../common/Common_H.h"
void UART_VoidInit(void);
void UART_VoidSend(u16 Data);
u8 UART_u8Receive(void);

#endif /* MCAL_COMMUNICATION_UART_UART_INTERFACE_H_ */
