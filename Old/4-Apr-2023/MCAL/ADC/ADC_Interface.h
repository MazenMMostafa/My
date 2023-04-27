/*
 * ADC_Interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
#include "ADC_Config.h"
#include "../DIO/DIO_Interface.h"
void ADC_ErrStateInit(void);
u8 ADC_ErrStateReadValue(u8 PIN);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
