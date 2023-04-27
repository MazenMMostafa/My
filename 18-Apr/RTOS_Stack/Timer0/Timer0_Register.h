/*
 * Timer_Register.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMER_TIMER0_TIMER0_REGISTER_H_
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../common/Definition.h"
/* Timer Control Register */
#define TCCR0_Reg (*(volatile u8*)0x53)
/* Timer Counter Register */
#define TCNT0_Reg (*(volatile u8*)0x52)
/* Output Compare Register */
#define OCR0_Reg (*(volatile u8*)0x5C)
/* Interrupt Mask Register */
#define TIMSK_Reg (*(volatile u8*)0x59)
/* Interrupt Flag Register */
#define TIFR_Reg (*(volatile u8*)0x59)

#define SFIOR_Reg (*(volatile u8*)0x50)
#endif /* MCAL_TIMER_TIMER0_TIMER0_REGISTER_H_ */
