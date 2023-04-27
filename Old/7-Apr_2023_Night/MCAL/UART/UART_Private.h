/*
 * UART_Private.h
 *
 *  Created on: Apr 7, 2023
 *      Author: Mazen
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

/* UCSRA */
#define U2X 1 /* USART Double Speed */
#define PE 2 /* Parity Error */
#define DOR 3 /* Data OverRun */
#define FE 4 /* Frame Error */
#define UDRE 5 /* Data Register Empty*/
#define TXC 6 /* Transmit complete */
#define RXC 7 /* Recieve complete*/
/* UCSRB */
#define TXB8 0   /*  Transmit Data Bit 8 */
#define RXB8 1   /* Receive Data Bit 8 */
#define UCSZ2 2  /* Character Size */
#define TXEN 3   /*  Transmitter Enable */
#define RXEN 4   /* Receiver Enable */
#define UDRIE 5  /* USART Data Register Empty Interrupt Enable */
#define TXCIE 6  /* TX Complete Interrupt Enable */
#define RXCIE 7  /* RX Complete Interrupt Enable */
//URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL
/* UCSRC page 163*/
#define UCPOL 0 /* Clock Polarity */
#define UCSZ0 1 /* Character Size */
#define UCSZ1 2 /* Character Size */
#define USBS  3 /*  Stop Bit Select */
#define UPM0  4 /* Parity Mode */
#define UPM1  5 /* Parity Mode */
#define UMSEL 6 /* USART Mode Select */
#define URSEL 7 /* Register Select */
#endif /* MCAL_UART_UART_PRIVATE_H_ */
