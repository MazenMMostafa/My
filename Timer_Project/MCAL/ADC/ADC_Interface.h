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
ADC_ErrState ADC_ErrStateInit(void);
ADC_ErrState ADC_ErrStateConversionSynch(u8 PIN,u16 *Val);
/* Enable Global Interrupt Before calling this function */
ADC_ErrState ADC_ErrStateConversionASynch(u8 PIN,u16 *Val,void (*ADC_pvCallBackNotifFunc)(void));
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
