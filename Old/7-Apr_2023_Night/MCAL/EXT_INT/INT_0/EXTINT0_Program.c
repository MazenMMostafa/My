/*
 * EXTINT0_Program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#include "EXTINT0_Interface.h"
void (*INT0_CallbackAddress)(void)=Null;

void INT0_VoidSETINT0(void){
	EnableGlobalInterrupt();
	ENABLEINT0_GICR_Reg;
#if CaseINT0==INT0_LowLevel
	ENABLEINT0_LOW_LEVEL;
#endif
#if CaseINT0==INT0_AnyLogicalChange
	ENABLEINT0_ANY_LOGIC;
#endif
#if CaseINT0 ==INT0_FallingEdge
	ENABLEINT0_FALLING_EDGE;
#endif
#if CaseINT0==INT0_RisingEdge
	ENABLEINT0_RISING_EDGE;
#endif
}

INT0_Err INT0_SetCallBack(void (*INT0CB)(void)){
if(INT0CB != Null){
	INT0CB=INT0_CallbackAddress;
	}
else{
	return INT0_PTR_NULL;
}
return INT0_PTR_OK;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){

	if(INT0_CallbackAddress!=Null){
		INT0_CallbackAddress();
	}
	else{
		//nothing
	}
}


