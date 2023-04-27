/*
 * Keypad_Private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mazen
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_
#include "../../common/Definition.h"
#include "../../common/Type.h"
#include "../../common/bit-math.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
typedef struct{
	PORT_Name ROW_PORT1 ;
	PIN_Number ROW_PIN1  ;
	PORT_Name ROW_PORT2 ;
	PIN_Number ROW_PIN2  ;
	PORT_Name ROW_PORT3 ;
	PIN_Number ROW_PIN3  ;
	PORT_Name ROW_PORT4 ;
	PIN_Number ROW_PIN4  ;
}KeypadRow_PORT_PIN;
typedef struct{
	PORT_Name COL_PORT1 ;
	PIN_Number COL_PIN1  ;
	PORT_Name COL_PORT2 ;
	PIN_Number COL_PIN2  ;
	PORT_Name COL_PORT3 ;
	PIN_Number COL_PIN3  ;
	PORT_Name COL_PORT4 ;
	PIN_Number COL_PIN4  ;
}KeypadCol_PORT_PIN;
typedef enum{
	OK,
	Error
}KP_ErrState;

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_PRIVATE_H_ */
