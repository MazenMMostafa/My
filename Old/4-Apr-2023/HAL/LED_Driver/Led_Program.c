/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */
#include "../../Common/Definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led){
	u8 SetPinErrReturn;
	u8 SetValueErrReturnON;

	SetPinErrReturn=DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_OUT);
	if(SetPinErrReturn==DIO_ERROR_PORT||SetPinErrReturn==DIO_ERROR_Direction||SetPinErrReturn==DIO_ERROR_PIN){
		return LED_INIT_Error;
	}
	else{
		if(Led->ConnectionType==Source_Connection){
			// HIGH = ON
			SetValueErrReturnON=DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_HIGH);
			if(SetValueErrReturnON==DIO_ERROR_PORT||SetValueErrReturnON==DIO_ERROR_VALUE||SetValueErrReturnON==DIO_ERROR_PIN){
				return LED_ON_Error;
			}
			else
				return LED_ON_OK;
		}
		else if(Led->ConnectionType==Sink_Connection){
			// LOW = ON
			SetValueErrReturnON=DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_LOW);
			if(SetValueErrReturnON==DIO_ERROR_PORT||SetValueErrReturnON==DIO_ERROR_VALUE||SetValueErrReturnON==DIO_ERROR_PIN){
				return LED_ON_Error;
			}
			else
				return LED_ON_OK;
		}

	}
}


LedErrState	Led_LedErrStateTurnOff(Led_info *Led){
	u8 SetValueErrReturnOFF;
	if(Led->ConnectionType==Source_Connection){
		// HIGH = ON
		SetValueErrReturnOFF=DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_LOW);
		if(SetValueErrReturnOFF==DIO_ERROR_PORT||SetValueErrReturnOFF==DIO_ERROR_VALUE||SetValueErrReturnOFF==DIO_ERROR_PIN){
			return LED_OFF_Error;
		}
		else
			return LED_OFF_OK;
	}
else if(Led->ConnectionType==Sink_Connection){
	// LOW = ON
	SetValueErrReturnOFF=DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_HIGH);
	if(SetValueErrReturnOFF==DIO_ERROR_PORT||SetValueErrReturnOFF==DIO_ERROR_VALUE||SetValueErrReturnOFF==DIO_ERROR_PIN){
		return LED_OFF_Error;
	}
	else
		return LED_OFF_OK;
}

}


