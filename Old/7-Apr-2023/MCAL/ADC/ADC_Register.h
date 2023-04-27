/*
 * ADC_Register.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_
#include "../../common/Common_H.h"
#define ADMUX_Reg  (*(volatile u8*)0x27)
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define ADCSRA_Reg (*(volatile u8*)0x26)
#define ADEN 7 	/* 	ADC Enable 			     */
#define ADSC 6 	/* 	ADC Start conversion     */
#define ADATE 5 /*  ADC Auto Trigger Enable  */
#define ADIF 4  /*  ADC Interrupt Flag 	     *//* Should Enable SREG Global interrupt*/
					/*Cleared By HW*/
#define ADIE 3	/* Interrupt Enable *//* Should Enable SREG Global interrupt*/
/* Division Factor //Prescaler*/
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADCH_Reg   (*(volatile u8*)0x25)
#define ADCL_Reg   (*(volatile u8*)0x24)
#define SFIOR_Reg  (*(volatile u8*)0x50)
#define SREG_Reg   (*(volatile u8*)0x5F)

#endif /* MCAL_ADC_ADC_REGISTER_H_ */
