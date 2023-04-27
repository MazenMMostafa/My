/*
 * Keypad_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mazen
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#include "Keypad_Config.h"
u8	KP_ErrStateRead(KeypadRow_PORT_PIN *KP_RPP_INFO,KeypadCol_PORT_PIN *KP_CPP_INFO,u8 *ReadValue);
void KP_ErrStateInit(KeypadRow_PORT_PIN *KP_RPP_INFO,KeypadCol_PORT_PIN *KP_CPP_INFO);
#endif /* HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */
