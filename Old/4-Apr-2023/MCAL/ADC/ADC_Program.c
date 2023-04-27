/*
 * ADC_Program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#include "ADC_Interface.h"

void ADC_ErrStateInit(void){

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
}
u8 ADC_ErrStateReadValue(u8 PIN){
ADMUX_Reg&=0b11100000;
ADMUX_Reg|=PIN;
SET_BIT(ADCSRA_Reg,ADSC);
while((GET_BIT(ADCSRA_Reg,ADIF))==0);
SET_BIT(ADCSRA_Reg,ADIF);
return ADCH_Reg;
}
