/*
 * Timer0_Program.c
 *	RTOS Layer
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */


#include "Timer0_Interface.h"
static void (*T0_pvCallBackfun)(void)=Null;
void T0_VoidInit(void){
	/* Setting Prescaler*/
	Prescale;

	/* Setting CTC Mode On */
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM00);
	SET_BIT(TCCR0_Reg,TCCR0_WGM01);

	/* Enable T0 Interrupt */
	SET_BIT(TIMSK_Reg,TIMSK_OCIE0);
	CLEAR_BIT(TIMSK_Reg,TIMSK_TOIE0);

}
void Timer0_VoidSetOCR0(u8 *OCR0_Value){
	OCR0_Reg=*OCR0_Value;

}
u8 Timer0_u8SetCallBack(void (*Copy_pvCallBackfun)(void)){
	if(Copy_pvCallBackfun!=Null){
		T0_pvCallBackfun=Copy_pvCallBackfun;
		return 1;
	}
	else
		/*Nothing*/
		return 0;
}
//ISR(TIMER0_COMP_VECT)
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u16 counter=0;
	counter++;
	if(counter==IFCOND){
		//if(T0_pvCallBackfun!=Null){
		T0_pvCallBackfun();
		counter=0;
		//}
	}
}
