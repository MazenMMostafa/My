/*
 * Timer0_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */
#include "../../DIO/DIO_Interface.h"
#include "../../../common/Definition.h"
#include "Timer0_Register.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
//u32 Desired;
/*void CallBackTimer0(void(*Timer0)(void)){
	VoidNormalTimer0=Timer0;
}*/

void Time_0_Init(void){
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
	//CLEAR_BIT(TCCR0,7);
	//SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,5);
	//CLEAR_BIT(TCCR0,5);
}
void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{
	static u32 count;
	//DIO_ErrStateSetPinValue(PORT_A,PIN_0,DIO_HIGH);
/*	static u32 Ttick = 0;
	static u32 TOF = 0;
	static f32 SWCounts = 0;
	static f32 Preload = 0;
	static u32 count=0;
	static f32 t;
	Ttick = 8 / 8000000;
	TOF = (Ttick * 256);
	SWCounts = 1/ TOF;
	//t=(SWCounts - (u32)SWCounts);
//	Preload = 256-(t*256);
	*///if(VoidNormalTimer0!=Null){

	count++;
	OCR0=125;
		if(count == 0)
		{	TOGGLE_BIT(PORTA_ITI,0);
			//SET CALL BACK FUNCTION
			//count = 0;
			//TCNT0 = 90;

		}
		else if(count == 10)
		{	TOGGLE_BIT(PORTA_ITI,0);
			//SET CALL BACK FUNCTION
			//TCNT0 = 90;

		}
		else if(count==20){
			count=0;
		}

}
