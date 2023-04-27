/*
 * DIO.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mazen
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../common/bit-math.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include "../../common/Definition.h"
#include "../../common/Type.h"
/*	Setting Port as Input or Output Section
 *	It takes ({PORT_A,PORT_B,PORT_C,PORT_D},{PIN_0>PIN_7},{OUT,IN})
 *	return Error state
 * */
DIO_Err DIO_ErrStateSetPinDirection(PORT_Name port,PIN_Number pin,Direction direction);
//--------------------------------------------------//
/*	Setting Output Volt High or Low
*	It takes ({PORT_A,PORT_B,PORT_C,PORT_D},{PIN_0>PIN_7},{HIGH,LOW})
*	return Error state
* */
DIO_Err DIO_ErrStateSetPinValue(PORT_Name port,PIN_Number pin,Volt val);
//--------------------------------------------------//
/*	Reading Section
 * It takes ({PORT_A,PORT_B,PORT_C,PORT_D},{PIN_0>PIN_7},reading value address)
 * return Error State
 * */
DIO_Err DIO_ErrStateReadPinValue(PORT_Name port,PIN_Number pin,u8 *value);

DIO_Err DIO_ErrStateSetGroupDirection(PORT_Name port,Direction direction);

DIO_Err  DIO_ErrStateSetPortValue(PORT_Name port,Volt val);

DIO_Err  DIO_ErrStateReadGroupValue(PORT_Name port ,u8 *value);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
