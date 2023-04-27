/*
 * Timer0_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mazen
 */


#include "Timer0_Interface.h"
static void (*T0_pvCallBackfun)(void)=Null;
u32 IFCOND;
void T0_VoidInit(void){
	/* Setting Prescaler*/
	Prescale;
	u16 Ticktime,Presc=8;
	//Presc depends on Prescaler Number 8, 64, 256, 1024
	Ticktime=(float)Presc/(float)FCPU;

#if T0_Type==T0_Normal
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM00);
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM01);
#elif T0_Type==T0_PHPWM
	SET_BIT(TCCR0_Reg,TCCR0_WGM00);
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM01);
	/* Set Down Counting */
	// Period Time = 2*OverFlow
	//DutyCycle= (OverFlow - CompareTime)/OverFlow
	//DutyCycle=1-(Compare/OverFlow)

	/* Clear Down Counting */

#elif T0_Type==T0_CTC
	/* Setting CTC Mode On */
	CLEAR_BIT(TCCR0_Reg,TCCR0_WGM00);
	SET_BIT(TCCR0_Reg,TCCR0_WGM01);

	/* Enable T0 Interrupt */
	SET_BIT(TIMSK_Reg,TIMSK_OCIE0);
	CLEAR_BIT(TIMSK_Reg,TIMSK_TOIE0);

#elif T0_Type==T0_FastPWM
	SET_BIT(TCCR0_Reg,TCCR0_WGM00);
	SET_BIT(TCCR0_Reg,TCCR0_WGM01);
	//Period Time=OverFlow Time

	/* Clear On Top Set On Compare */
	//DutyCycle = (OverFlow Time -Compare Match Time)/OverFlow Time
	//DutyCycle= 1-(Compare Match Time/OverFlow Time)
	//Increasing CMT -> Decrease DutyCyle because of the (-)
#if T0_FPWM==T0_FPWM_CLRTOP
	SetFPWMType;

	/* Set On Top Clear On Compare */
	//DutyCycle=(Compare Match Time)/(OverFlow Time)
	// Increase CMT -> Increase DutyCycle
#elif T0_FPWM==T0_FPWM_CLRCTC
	SetFPWMType;
#endif
#endif
}
void Timer0_VoidSetOCR0(u8 OCR0_Value,u16 *Counter){
	OCR0_Reg=OCR0_Value;
	IFCOND=*Counter;
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
