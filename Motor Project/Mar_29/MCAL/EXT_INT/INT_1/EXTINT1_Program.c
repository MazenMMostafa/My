/*
 * EXTINT1_Program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */
#include "EXTINT1_Interface.h"

void (*INT1_CallbackAddress)(void)=Null;

void INT1_VoidSETINT1(void){
	EnableGlobalInterrupt();
	ENABLEINT1_GICR_Reg;
#if CaseINT1==INT1_LowLevel
	ENABLEINT1_LOW_LEVEL;
#endif
#if CaseINT1==INT0_AnyLogicalChange
	ENABLEINT1_ANY_LOGIC;
#endif
#if CaseINT1 ==INT1_FallingEdge
	ENABLEINT1_FALLING_EDGE;
#endif
#if CaseINT1==INT1_RisingEdge
	ENABLEINT1_RISING_EDGE;
#endif
}

INT1_Err INT1_SetCallBack(void (*INT1CB)(void)){
	if(INT1CB!=Null){
	INT1CB=INT1_CallbackAddress;
	}
	else{
		return INT1_PTR_NULL;
	}
	return INT1_PTR_OK;

}

void __vector_2 (void) __attribute__((signal));
void __vector_2(void){
	if(INT1_CallbackAddress!=Null){
		INT1_CallbackAddress();
	}
	else{
		//Do Nothing
	}
}
