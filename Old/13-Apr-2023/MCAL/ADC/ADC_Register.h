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


#define ADCH_Reg   (*(volatile u8*)0x25)
#define ADCL_Reg   (*(volatile u8*)0x24)
#define SFIOR_Reg  (*(volatile u8*)0x50)


#endif /* MCAL_ADC_ADC_REGISTER_H_ */
