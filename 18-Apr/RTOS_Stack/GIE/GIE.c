/*
 * Global_Interrupt_Enable.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */
#include "GIE.h"
void GIEEnable(void){
	ENABLEINT0_SREG;
}
