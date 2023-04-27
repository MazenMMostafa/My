/*
 * ADC_Program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#include "ADC_Interface.h"
static u16 * ADC_pu8Readibg = Null;
static void (*ADC_pvCallBackNotifFunc)(void)=Null;
static u8 ADC_State=ADC_IDLE;
ADC_ErrState ADC_ErrStateInit(void){

	//AVCC With External Cap
	CLEAR_BIT(ADMUX_Reg,REFS0);
	CLEAR_BIT(ADMUX_Reg,REFS1);

	//Left Adjust
	SET_BIT(ADMUX_Reg,ADLAR);

	ADCSRA_Reg&=ADC_PRESC_MASK;
	//Setting Prescale in Config file
	ADCSRA_Reg|=PRESC;
	//Enable
	SET_BIT(ADCSRA_Reg,ADEN);
	return ADC_Init_Ok;
}
ADC_ErrState ADC_ErrStateConversionSynch(u8 PIN,u16 *Val){
	u8 Adc_ErrReturn;
	if(ADC_State==ADC_IDLE){
		ADC_State=ADC_BUSY;
		u32 ADC_Local_Counter;
		ADMUX_Reg&=0b11100000;
		ADMUX_Reg|=PIN;
		SET_BIT(ADCSRA_Reg,ADSC);
		while(((GET_BIT(ADCSRA_Reg,ADIF))==0)&&(ADC_Local_Counter!=ADC_u32Timeout)){
			ADC_Local_Counter++;
		}
		if(ADC_Local_Counter==ADC_u32Timeout){
			Adc_ErrReturn= ADC_SynchError;
		}
		else
		{

			SET_BIT(ADCSRA_Reg,ADIF);
			*Val=ADCH_Reg;
			Adc_ErrReturn=ADC_Synch_Ok;
		}
	}
	else{
		Adc_ErrReturn=ADC_Synch_Busy;
	}
	ADC_State=ADC_IDLE;
	return Adc_ErrReturn;
}
ADC_ErrState ADC_ErrStateConversionASynch(u8 PIN,u16 *Val,void (*ADC_pvNotifFunc)(void)){
	u8 Adc_ErrReturn;
	if(ADC_State==ADC_IDLE){

		if(Val==Null || ADC_pvNotifFunc==Null){
			Adc_ErrReturn=ADC_ASynchError;
		}
		else
		{
			ADC_State=ADC_BUSY;
			ADC_pu8Readibg=Val;
			ADC_pvCallBackNotifFunc=ADC_pvNotifFunc;
			/* Clear MUX Register */
			ADMUX_Reg&=0b11100000;
			/* Set the required channel into MUX bits */
			ADMUX_Reg|=PIN;
			/* Start Conversion */
			SET_BIT(ADCSRA_Reg,ADSC);
			/* Enable ADC Interrupt */
			SET_BIT(ADCSRA_Reg,ADIE);
			Adc_ErrReturn=ADC_ASynch_Ok;
		}
	}
	else{
		Adc_ErrReturn=ADC_ASynch_Busy;
	}
	return Adc_ErrReturn;
}
void __vector_16(void) __attribute__((signal));
void __vector_16(void){
	/* Read adc result */
	*ADC_pu8Readibg= ADCH_Reg;
	/* Invoke Callback NotiFun */
	ADC_pvCallBackNotifFunc();
	/* Disable ADC Conversion */
	CLEAR_BIT(ADCSRA_Reg,ADIE);
	ADC_State=ADC_IDLE;
}
