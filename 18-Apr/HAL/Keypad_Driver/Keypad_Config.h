/*
 * Keypad_Config.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mazen
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_
#include "Keypad_Private.h"
/*	Keypad Rows	*/
#define KP_ROW_PIN1 0
#define KP_ROW_PIN2 1
#define KP_ROW_PIN3 2
#define KP_ROW_PIN4 3
typedef enum{
KP_ROW_PORT1='A',
KP_ROW_PORT2='A',
KP_ROW_PORT3='A',
KP_ROW_PORT4='A'
}KPRPORT;
/*	Keypad Coloumns */
#define KP_COL_PIN1 4
#define KP_COL_PIN2 5
#define KP_COL_PIN3 6
#define KP_COL_PIN4 7
typedef enum{
	KP_COL_PORT1='A',
	KP_COL_PORT2='A',
	KP_COL_PORT3='A',
	KP_COL_PORT4='A'
}KPCPORT;

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_ */
