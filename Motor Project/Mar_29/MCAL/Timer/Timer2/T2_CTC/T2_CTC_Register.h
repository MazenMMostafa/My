/*
 * Timer_Register.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_CTC_REGISTER_H_
#define MCAL_TIMER_TIMER2_TIMER2_CTC_REGISTER_H_
#include "../../../DIO/DIO_Interface.h"
#include "../../../../common/Common_H.h"

#define TIMSK_Reg (*(volatile u8*)0x59)
#define TCCR2_Reg (*(volatile u8*)0x45)
#define OCR2_Reg (*(volatile u8*)0x43)

#endif /* MCAL_TIMER_TIMER0_TIMER0_REGISTER_H_ */
