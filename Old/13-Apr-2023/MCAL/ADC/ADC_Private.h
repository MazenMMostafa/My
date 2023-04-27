/*
 * ADC_Private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Mazen
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
#include "ADC_Register.h"

typedef enum{MUX0,MUX1,MUX2,MUX3,MUX4}MUX_t;
typedef enum{ADC_BUSY,ADC_IDLE}ADC_STATE_t;

// For ADLAR = 0
/*
 * 15 14 13 12 11 10  	9 	8
	–  –  –  –  –  –   ADC9 ADC8 ADCH
ADC7 ADC6 ADC5 ADC4 ADC3 ADC2 ADC1 ADC0 ADCL
 7	  6	   5	 4	 3	  2	   1	 0
 */
//For ADLAR = 1
/*
 *   15  14    13   12   11   10    9   8
	ADC9 ADC8 ADC7 ADC6 ADC5 ADC4 ADC3 ADC2 ADCH
	ADC1 ADC0  –    –     –    –   –     –  ADCL
	 7     6   5    4     3    2   1     0
 */

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC8,
	ADC9
}ADLAR_t;

#define ADTS0 5
#define ADTS1 6
#define ADTS2 7
typedef enum{
	ADC_Init_Ok,
	ADC_Synch_Ok,
	ADC_ASynch_Ok,
	ADC_Synch_Busy,
	ADC_ASynch_Busy,
	ADC_SynchError,
	ADC_ASynchError,
	ADC_InitErr

}ADC_ErrState;

#define DivTwo 0
#define DivFour 2
#define DivEight 3
#define DivSixteen 4
#define DivThirtytwo 5
#define DivSixtyfour 6
#define DivHTE 7

#define ADEN 7 	/* 	ADC Enable 			     */
#define ADSC 6 	/* 	ADC Start conversion     */
#define ADATE 5 /*  ADC Auto Trigger Enable  */
#define ADIF 4  /*  ADC Interrupt Flag 	     *//* Should Enable SREG Global interrupt*/
					/*Cleared By HW*/
#define ADIE 3	/* Interrupt Enable *//* Should Enable SREG Global interrupt*/
/* Division Factor //Prescaler*/
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
#define ADC_PRESC_MASK 0b11111000
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
