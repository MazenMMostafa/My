/*
 * Keypad_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Mazen
 */
#include"Keypad_Interface.h"
u8 KP_Arr[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
};
void KP_ErrStateInit(KeypadRow_PORT_PIN *KP_RPP_INFO,KeypadCol_PORT_PIN *KP_CPP_INFO){
	//u8 ROW,COL,ReadPin;
	//KPRPORT ROWP=KP_ROW_PORT1;
	//KPCPORT COLP=KP_COL_PORT1;
		DIO_ErrStateSetPinDirection(PORT_C,KP_RPP_INFO->ROW_PIN1,DIO_OUT);
		DIO_ErrStateSetPinDirection(PORT_C,KP_RPP_INFO->ROW_PIN2,DIO_OUT);
		DIO_ErrStateSetPinDirection(PORT_C,KP_RPP_INFO->ROW_PIN3,DIO_OUT);
		DIO_ErrStateSetPinDirection(PORT_C,KP_RPP_INFO->ROW_PIN4,DIO_OUT);
		DIO_ErrStateSetPinDirection(PORT_C,KP_CPP_INFO->COL_PIN1,DIO_IN);
		DIO_ErrStateSetPinDirection(PORT_C,KP_CPP_INFO->COL_PIN2,DIO_IN);
		DIO_ErrStateSetPinDirection(PORT_C,KP_CPP_INFO->COL_PIN3,DIO_IN);
		DIO_ErrStateSetPinDirection(PORT_C,KP_CPP_INFO->COL_PIN4,DIO_IN);
		DIO_ErrStateSetPinValue(PORT_C,KP_RPP_INFO->ROW_PIN1,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_RPP_INFO->ROW_PIN2,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_RPP_INFO->ROW_PIN3,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_RPP_INFO->ROW_PIN4,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_CPP_INFO->COL_PIN1,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_CPP_INFO->COL_PIN2,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_CPP_INFO->COL_PIN3,DIO_HIGH);
		DIO_ErrStateSetPinValue(PORT_C,KP_CPP_INFO->COL_PIN4,DIO_HIGH);

}
KP_ErrState	KP_ErrStateRead(KeypadRow_PORT_PIN *KP_RPP_INFO,KeypadCol_PORT_PIN *KP_CPP_INFO,u8 *ReadValue){
	u8 ROW,COL,ReadPin;
	u8 ErrVal;
	//_delay_ms(100);
	for(ROW=0;ROW<4;ROW++){
		DIO_ErrStateSetPinValue(PORT_C,ROW,DIO_LOW);

		for(COL=4;COL<8;COL++){
			ErrVal=DIO_ErrStateReadPinValue(PORT_C,COL,&ReadPin);
			_delay_ms(30);
			if(ErrVal==DIO_OK&&ReadPin==0){
				DIO_ErrStateSetPinDirection(PORT_D,PIN_0,DIO_OUT);
				DIO_ErrStateSetPinValue(PORT_D,PIN_0,DIO_HIGH);
				DIO_ErrStateSetPinValue(PORT_C,ROW,DIO_HIGH);
				//_delay_ms(30);
				*ReadValue =KP_Arr[ROW][COL-4];
				// test could be removed
				while(ReadPin==0){
					DIO_ErrStateReadPinValue(PORT_C,COL,&ReadPin);
					if(ReadPin==1)
						break;
				}
				return OK;
			}
		}
		DIO_ErrStateSetPinValue(PORT_C,ROW,DIO_HIGH);
	}
	return Error;
	//Flag=0;
}
