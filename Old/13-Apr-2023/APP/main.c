/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Mazen
 */
#include "../HAL/LCD_Driver/LCD_Interface.h"
#include "../MCAL/Global_Interrupt_Enable.h"
#include "../MCAL/Timer/Timer0/Timer0_Interface.h"

//u8 Button,Mode=1,Read;
//LCD_Line_Info type ={YES,NO};LCD_Line_Info type2 ={NO,YES};
//LCD_Info lcd={RS_PORT,RS_PIN,RW_PORT,RW_PIN,E_PORT,E_PIN,DATA_PORT};
//KeypadRow_PORT_PIN RPP={KP_ROW_PORT1,KP_ROW_PIN1,KP_ROW_PORT2,KP_ROW_PIN2,KP_ROW_PORT3,KP_ROW_PIN3,KP_ROW_PORT4,KP_ROW_PIN4};
//KeypadCol_PORT_PIN CPP={KP_COL_PORT1,KP_COL_PIN1,KP_COL_PORT2,KP_COL_PIN2,KP_COL_PORT3,KP_COL_PIN3,KP_COL_PORT4,KP_COL_PIN4};

//Switch_Info PB ={PORT_D,PIN_2,InternalPullUp};
void PWMFun(void);
void main()
{u16 i;
	EnableGlobalInterrupt();
	T0_VoidInit();
	//LCD_VoidInit(&lcd);

	while(1){

	}

}

void PWMFun(void){
	TOGGLE_BIT(PORTA_ITI,PIN_0);
}
