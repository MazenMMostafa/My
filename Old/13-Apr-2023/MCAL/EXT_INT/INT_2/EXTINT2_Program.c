/*
 * EXTINT2_Program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */
#include "EXTINT2_Interface.h"
void (*INT2_CallbackAddress)(void)=Null;

void INT2_VoidSETINT2(void){
EnableGlobalInterrupt();
ENABLEINT2_GICR_Reg;
ENABLEINT2_FALLING_EDGE;
}
INT2_Err INT2_SetCallBack(void (*INT2CB)(void)){
	if(INT2CB!=Null){
	INT2CB=INT2_CallbackAddress;
	}
	else
	{
		return INT2_PTR_NULL;
	}
	return INT2_PTR_OK;
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
if(INT2_CallbackAddress!=Null){
	INT2_CallbackAddress();
}
else{
//Nothing
}
}
