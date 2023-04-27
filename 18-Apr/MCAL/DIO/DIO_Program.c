/*
 * DIO.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Mazen
 */

#include "DIO_Interface.h"

DIO_Err DIO_ErrStateSetPinDirection(PORT_Name port,PIN_Number pin,Direction direction){
	if(pin>=0 && pin<=7)
		{
			if(direction == DIO_OUT)
			{
				switch(port)
				{
				case 'A': SET_BIT(DDRA_ITI,pin); break;
				case 'B': SET_BIT(DDRB_ITI,pin); break;
				case 'C': SET_BIT(DDRC_ITI,pin); break;
				case 'D': SET_BIT(DDRD_ITI,pin); break;
				default: return DIO_ERROR_PORT;
				}

			}
			else if(direction == DIO_IN)
			{
				switch(port)
				{
				case 'A': CLEAR_BIT(DDRA_ITI,pin); break;
				case 'B': CLEAR_BIT(DDRB_ITI,pin); break;
				case 'C': CLEAR_BIT(DDRC_ITI,pin); break;
				case 'D': CLEAR_BIT(DDRD_ITI,pin); break;
				default: return DIO_ERROR_PORT;				}
			}
			else
				return DIO_ERROR_Direction;
		}
	else
		return DIO_ERROR_PIN;
	return DIO_OK;
}
DIO_Err DIO_ErrStateSetPinValue(PORT_Name port,PIN_Number pin,Volt val){
	if(pin>=0 && pin<=7)
			{
				if(val == DIO_HIGH)
				{
					switch(port)
					{
					case 'A': SET_BIT(PORTA_ITI,pin); break;
					case 'B': SET_BIT(PORTB_ITI,pin); break;
					case 'C': SET_BIT(PORTC_ITI,pin); break;
					case 'D': SET_BIT(PORTD_ITI,pin); break;
					default: return DIO_ERROR_PORT;
					}
				}
				else if(val == DIO_LOW)
				{
					switch(port)
					{
					case 'A': CLEAR_BIT(PORTA_ITI,pin); break;
					case 'B': CLEAR_BIT(PORTB_ITI,pin); break;
					case 'C': CLEAR_BIT(PORTC_ITI,pin); break;
					case 'D': CLEAR_BIT(PORTD_ITI,pin); break;
					default: return DIO_ERROR_PORT;					}
				}
				else
					return DIO_ERROR_VALUE;
			}
		else
			return DIO_ERROR_PIN;
		return DIO_OK;
}
DIO_Err DIO_ErrStateReadPinValue(PORT_Name port,PIN_Number pin,u8 *value){
	if(pin>=0 && pin<=7)
				{
						switch(port)
						{
						case 'A':*value= GET_BIT(PINA_ITI,pin); break;
						case 'B':*value= GET_BIT(PINB_ITI,pin); break;
						case 'C':*value= GET_BIT(PINC_ITI,pin); break;
						case 'D':*value= GET_BIT(PIND_ITI,pin); break;
						default: return DIO_ERROR_PORT;
						}

				}
			else
				return DIO_ERROR_PIN;
			return DIO_OK;
}

DIO_Err  DIO_ErrStateSetGroupDirection(PORT_Name port ,Direction direction)
{
	if (direction <= 0xff && direction>=0x00)
	{
		switch(port)
		{
		case 'A': DDRA_ITI =   direction ;break ;
		case 'B': DDRB_ITI =   direction ;break ;
		case 'C': DDRC_ITI =   direction ;break ;
		case 'D': DDRD_ITI =   direction ;break ;
		default :
			return DIO_ERROR_PORT ;
		}
		return DIO_OK ;
	}
	else
	{
		return DIO_ERROR_Direction;
	}
}
DIO_Err  DIO_ErrStateSetPortValue(PORT_Name port,Volt val)
{
	if (val <= 0xff && val>=0x00)
	{
		switch(port)
		{
		case 'A':  PORTA_ITI =  val ;break ;
		case 'B':  PORTB_ITI =  val ;break ;
		case 'C':  PORTC_ITI =  val ;break ;
		case 'D':  PORTD_ITI =  val ;break ;
		default :
			return DIO_ERROR_PORT ;
		}
		return DIO_OK ;
	}
	else
	{
		return DIO_ERROR_VALUE;
	}

}
DIO_Err  DIO_ErrStateReadGroupValue(PORT_Name port ,u8 *value)
{
	if(value!=Null)
	{
		switch(port)
		{
		case 'A':  *value = PINA_ITI ; break ;
		case 'B':  *value = PINB_ITI ; break ;
		case 'C':  *value = PINC_ITI ; break ;
		case 'D':  *value = PIND_ITI ; break ;
		default :
			return DIO_ERROR_PORT ;
		}
		return DIO_OK ;
	}
	else
	{
		return AddressError;
	}

}
