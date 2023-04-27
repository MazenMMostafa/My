#include "Seg_Interface.h"

u8 SevSegCA_Arr[SevSeg_ArrSize]=
{		SevSegCA_0 ,
		SevSegCA_1 ,
		SevSegCA_2 ,
		SevSegCA_3 ,
		SevSegCA_4 ,
		SevSegCA_5 ,
		SevSegCA_6 ,
		SevSegCA_7 ,
		SevSegCA_8 ,
		SevSegCA_9 ,
};

u8 SevSegCC_Arr[SevSeg_ArrSize]=
{		SevSegCC_0 ,
		SevSegCC_1 ,
		SevSegCC_2 ,
		SevSegCC_3 ,
		SevSegCC_4 ,
		SevSegCC_5 ,
		SevSegCC_6 ,
		SevSegCC_7 ,
		SevSegCC_8 ,
		SevSegCC_9
};
SevErrState SevSeg_SevErrStateSetNumber(u8 INPUT_NUMBER , SevSeg_info * SevenSegment1){
	u8 ErrStateDirection,ErrStateValue; // anode 1 // cathode 0 Enable
	ErrStateDirection=DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,DIO_OUT);
	if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction)
	{
		return Group_ERROR;
	}
	else{
		if(SevenSegment1->SevSeg_Type==CA){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
				if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE||ErrStateValue==DIO_ERROR_PIN){
					return Number_Error;
				}
				else{
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCA_Arr[INPUT_NUMBER]);
					if((ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE)&&((INPUT_NUMBER <0 )&&(INPUT_NUMBER>9))){
						return Number_Error;
					}
					else
						return Seven_OK;
				}
			}
		}
		else if(SevenSegment1->SevSeg_Type==CC){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
				if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE||ErrStateValue==DIO_ERROR_PIN){
					return Number_Error;
				}
				else{
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCC_Arr[INPUT_NUMBER]);
					if((ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE)&&((INPUT_NUMBER <0) &&(INPUT_NUMBER>9))){
						return Number_Error;
					}
					else
						return Seven_OK;
				}
			}
		}
	}
	return Seven_OK;
}

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End ){
	u8 ErrStateDirection,ErrStateValue;
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,DIO_OUT);
	if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction)
	{
		return Group_ERROR;
	}
	else{
		if(SevenSegment1->SevSeg_Type==CA){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
				if((ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE)&&((Copy_start <0) &&(Copy_End>9))){
					return Number_Error;
				}
				else{
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCA_Arr[Copy_start]);
					_delay_ms(500);
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCA_Arr[Copy_End]);
					_delay_ms(500);
				}
			}
		}
		else if(SevenSegment1->SevSeg_Type==CC){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
				if((ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE)&&((Copy_start <0) &&(Copy_End>9))){
					return Number_Error;
				}
				else{
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCC_Arr[Copy_start]);
					_delay_ms(500);
					ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCC_Arr[Copy_End]);
					_delay_ms(500);
				}
			}
		}
	}
	return Seven_OK;

}

SevErrState SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1){
	u8 ErrStateDirection,ErrStateValue; // anode 1 // cathode 0 Enable
	ErrStateDirection=DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,DIO_OUT);
	if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction)
	{
		return Group_ERROR;
	}
	else{
		if(SevenSegment1->SevSeg_Type==CA){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
				if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE||ErrStateValue==DIO_ERROR_PIN){
					return Number_Error;
				}
				else{
					for(u8 i=0;i<10;i++){
						ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCA_Arr[i]);
						_delay_ms(150);
					}
					if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE){
						return Number_Error;
					}
					else
						return Seven_OK;
				}
			}
		}
		else if(SevenSegment1->SevSeg_Type==CC){
			ErrStateDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUT);
			if(ErrStateDirection==DIO_ERROR_PORT||ErrStateDirection==DIO_ERROR_Direction||ErrStateDirection==DIO_ERROR_PIN){
				return Group_ERROR;
			}
			else
				{
				ErrStateValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
				if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE||ErrStateValue==DIO_ERROR_PIN){
					return Number_Error;
				}
				else{
					for(u8 i=0;i<10;i++){
						ErrStateValue=DIO_ErrStateSetPortValue(SevenSegment1->SevSeg_Group,SevSegCC_Arr[i]);
						_delay_ms(150);
					}
					if(ErrStateValue==DIO_ERROR_PORT||ErrStateValue==DIO_ERROR_VALUE){
						return Number_Error;
					}
					else
						return Seven_OK;
				}
			}
		}
	}
	return Seven_OK;
}
