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
	ADC_Ok,
	ADC_InitErr,
	ADC_InitOk
}ADC_ErrState;

#define DivTwo 0
#define DivFour 2
#define DivEight 3
#define DivSixteen 4
#define DivThirtytwo 5
#define DivSixtyfour 6
#define DivHTE 7

#define ADC_PRESC_MASK 0b11111000
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
