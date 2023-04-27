/*
 * Timer0_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */


#include "Timer0_Interface.h"
static void (*T0_pvCallBackfun)(void)=Null;
void T0_VoidInit(void){

#if T0_Type==T0_Normal
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM00);
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM01);
#elif T0_Type==T0_PWM
	SET_BIT(TCCR0_Reg,TCCR0_WGM00);
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM01);
#elif T0_Type==T0_PhaseCorrect
	SET_BIT(TCCR0_Reg,TCCR0_WGM00);
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM01);
#elif T0_Type==T0_CTC
	/* Setting CTC Mode On */
CLEAR_BIT(TCCR0_Reg,TCCR0_WGM00);
SET_BIT(TCCR0_Reg,TCCR0_WGM01);

/* Enable T0 Interrupt */
SET_BIT(TIMSK_Reg,TIMSK_OCIE0);
CLEAR_BIT(TIMSK_Reg,TIMSK_TOIE0);

/* Set Compare Match Value */
OCR0_Reg=250;

/* Setting Prescaler 8 */
CLEAR_BIT(TCCR0_Reg,TCCR0_CS00);
SET_BIT(TCCR0_Reg,TCCR0_CS01);
CLEAR_BIT(TCCR0_Reg,TCCR0_CS02);

#elif T0_Type==T0_FastPWM
SET_BIT(TCCR0_Reg,TCCR0_WGM00);
SET_BIT(TCCR0_Reg,TCCR0_WGM01);
#endif
}
u8 Timer0_u8SetCallBack(void (*Copy_pvCallBackfun)(void)){
if(Copy_pvCallBackfun!=Null)
	T0_pvCallBackfun=Copy_pvCallBackfun;
else
	/*Nothing*/
	return 1;
}
//ISR(TIMER0_COMP_VECT)
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u16 counter=0;
	counter++;
	if(counter==4000){
	//if(T0_pvCallBackfun!=Null){
		T0_pvCallBackfun();
		counter=0;
	//}
	}
}
