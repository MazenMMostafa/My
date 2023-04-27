/*
 * EXTINT0_Program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#include "EXTINT0_Interface.h"
void (*INT0_CallbackAddress)(void)=Null;

void INT0_VoidSETINT0(void){
	DIO_ErrStateSetPinDirection(PORT_D,PIN_2,DIO_IN);
	DIO_ErrStateSetPinValue(PORT_D,PIN_2,DIO_HIGH);
	SET_BIT(GICR_Reg,GICR_INT0_BIT);
	//ENABLEINT0_GICR_Reg;

#if CaseINT0==INT0_LowLevel
	ENABLEINT0_LOW_LEVEL;

#elif CaseINT0==INT0_AnyLogicalChange
	ENABLEINT0_ANY_LOGIC;

#elif CaseINT0 ==INT0_FallingEdge
	//ENABLEINT0_FALLING_EDGE;
	CLEAR_BIT(MCUCR_Reg,ISC00);
	SET_BIT(MCUCR_Reg,ISC01);

#elif CaseINT0==INT0_RisingEdge
	ENABLEINT0_RISING_EDGE;
#endif
}

INT0_Err INT0_SetCallBack(void (*INT0CB)(void)){
if(INT0CB != Null){
	INT0_CallbackAddress=INT0CB;
	}
else{
	return INT0_PTR_NULL;
}
return INT0_PTR_OK;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){

//	if(INT0_CallbackAddress!=Null){
		INT0_CallbackAddress();

//	}
	//else{
		//nothing
	//}
}


