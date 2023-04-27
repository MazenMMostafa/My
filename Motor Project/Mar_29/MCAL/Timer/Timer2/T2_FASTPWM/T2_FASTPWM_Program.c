/*
 * Timer2_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */

#include "T2_FASTPWM_Interface.h"
#include "../T2_Mode.h"
#if Mode==FPWM

void T2_VoidFPWMInit(void){
	/* Set fast pwm  */
	CLEAR_BIT(TCCR2_Reg,TCCR2_FPWM_FOC2);
	/* Set CTC Mode */
	SET_BIT(TCCR2_Reg,TCCR2_FPWM_WGM20);
	SET_BIT(TCCR2_Reg,TCCR2_FPWM_WGM21);
	/* Inverting Mode */
	SET_BIT(TCCR2_Reg,TCCR2_FPWM_COM20);
	SET_BIT(TCCR2_Reg,TCCR2_FPWM_COM21);
	/* Prescale 8bit */
	Set_Prescaler;
	/* Enable Interrupt */
	SET_BIT(TIMSK_Reg,TIMSK_FPWM_OCIE2);
	CLEAR_BIT(TIMSK_Reg,TIMSK_FPWM_TOIE2);

}
void T2_VoidSetOCR2(u8 OCR){
	OCR2_Reg=OCR;

}
/* Sequence is */
/* the global pointer to function is called in ISR
 * After it take the function that make the job
 * this function comes from main by calling T2_VoidSetCallback
 * */


void __vector_4(void) __attribute__((signal));
void __vector_4(void){




}

#endif
