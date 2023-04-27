/*
 * DIO_MACROS.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mazen
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/* Error State*/
typedef enum Error_state{DIO_OK,DIO_ERROR_PORT,DIO_ERROR_PIN,DIO_ERROR_Direction,DIO_ERROR_VALUE,AddressError}DIO_Err;
/*input and output and voltage rate Section*/
 typedef enum {
 DIO_LOW,
 DIO_HIGH
 }Volt;
typedef enum{
	 DIO_IN,
	DIO_OUT
 }Direction;
/*Ports Section*/
typedef enum PORTS{
 PORT_A= 'A',
 PORT_B,
 PORT_C,
 PORT_D
}PORT_Name;
/*Pins Section*/
typedef enum Pins
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}PIN_Number;
#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
