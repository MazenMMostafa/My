/*
 * Timer2_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#include "T2_CTC_Interface.h"
#include "../T2_Mode.h"
#if Mode==CTC
static u16 TimeCTC;
void (*T2_pvCallbackFun)(void)=Null;
void T2_VoidInit(void){
	/* Set Non pwm CTC */
	SET_BIT(TCCR2_Reg,TCCR2_FOC2);
	/* Set CTC Mode */
	SET_BIT(TCCR2_Reg,TCCR2_WGM21);
	CLEAR_BIT(TCCR2_Reg,TCCR2_WGM20);
	/* Normal port */
	CLEAR_BIT(TCCR2_Reg,TCCR2_COM20);
	CLEAR_BIT(TCCR2_Reg,TCCR2_COM21);
	/* Prescale 8bit */
	CLEAR_BIT(TCCR2_Reg,TCCR2_CS20);
	SET_BIT(TCCR2_Reg,TCCR2_CS21);
	CLEAR_BIT(TCCR2_Reg,TCCR2_CS22);
	/* Enable Interrupt */
	SET_BIT(TIMSK_Reg,TIMSK_OCIE2);
	CLEAR_BIT(TIMSK_Reg,TIMSK_TOIE2);

}
void T2_VoidSetOCR2(u8 OCR,u16 *Count){
	OCR2_Reg=OCR;
	TimeCTC=*Count;
}
/* Sequence is */
/* the global pointer to function is called in ISR
 * After it take the function that make the job
 * this function comes from main by calling T2_VoidSetCallback
 * */
void T2_VoidSetCallback(void (*T2Copy_CallBack)(void)){
if(T2Copy_CallBack!=Null){
	T2_pvCallbackFun=T2Copy_CallBack;
}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void){
static u16 Counter;
Counter++;
if(Counter==TimeCTC){
	T2_pvCallbackFun();
}

}
#endif
