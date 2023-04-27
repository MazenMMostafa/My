/*
 * register.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mazen
 */
#ifndef REGISTER_H_
#define REGISTER_H_
#include "../../common/Type.h"

/************************************************************************/
/*				DIO PORTS Registers                                     */
/************************************************************************/
/*PORT A*/
#define PORTA_ITI *((volatile u8*)0x3B)
#define  DDRA_ITI *((volatile u8*)0x3A)
#define  PINA_ITI *((volatile u8*)0x39)
/*PORT B*/
#define PORTB_ITI *((volatile u8*) 0x38)
#define  DDRB_ITI *((volatile u8*)0x37)
#define  PINB_ITI *((volatile u8*)0x36)
/*PORT C*/
#define PORTC_ITI *((volatile u8*) 0x35)
#define  DDRC_ITI *((volatile u8*)0x34)
#define  PINC_ITI *((volatile u8*)0x33)
/*PORT D*/
#define PORTD_ITI *((volatile u8*) 0x32)
#define  DDRD_ITI *((volatile u8*)0x31)
#define  PIND_ITI *((volatile u8*)0x30)


#endif /*REGISTER_H_ */
