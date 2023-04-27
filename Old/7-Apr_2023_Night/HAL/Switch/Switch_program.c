/*
 * Switch_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#include "Switch_Interface.h"
SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,u8 * Result){
	u8 read_val;
	Result=&read_val;
	u8 Switch_ErrDirectionReturn;
	u8 Switch_ErrValueReturn;
	if(Switch->ConnectionType==InternalPullUp){
		Switch_ErrDirectionReturn=DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_IN);
		if(Switch_ErrDirectionReturn==DIO_ERROR_PORT||Switch_ErrDirectionReturn==DIO_ERROR_Direction||Switch_ErrDirectionReturn==DIO_ERROR_PIN){
			return Switch_Init_Error;
		}
		else{
			DIO_ErrStateSetPinValue(Switch->SW_Group,Switch->SW_Pin,DIO_HIGH);
			Switch_ErrValueReturn=DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&read_val);
			if(Switch_ErrValueReturn==DIO_ERROR_PIN||Switch_ErrValueReturn==DIO_ERROR_PORT){
				return Switch_Value_Error;
			}
			else
				return Switch_Ok;
		}
	}
	else if(Switch->ConnectionType==ExternalPullUp){
		Switch_ErrDirectionReturn=DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_IN);
		Switch_ErrValueReturn=DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&read_val);
		if(Switch_ErrValueReturn==DIO_ERROR_PIN||Switch_ErrValueReturn==DIO_ERROR_PORT){
			return Switch_Value_Error;
		}
		else
			return Switch_Ok;
	}

	else if(Switch->ConnectionType==ExternalPullDown){
		Switch_ErrDirectionReturn=DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_IN);
		Switch_ErrValueReturn=DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&read_val);
		if(Switch_ErrValueReturn==DIO_ERROR_PIN||Switch_ErrValueReturn==DIO_ERROR_PORT){
			return Switch_Value_Error;
		}
		else
			return Switch_Ok;
	}

}
