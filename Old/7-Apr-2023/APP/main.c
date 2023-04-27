/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Mazen
 */
#include"../HAL/LCD_Driver/LCD_Interface.h"
#include "../HAL/Keypad_Driver/Keypad_Interface.h"
#include "../HAL/LED_Driver/Led_Interface.h"
#include "../MCAL/Timer/Timer0/Timer0_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"

//Led_info Led={PORT_D,PIN_0,Source_Connection};

//KeypadRow_PORT_PIN row={PORT_C,PIN_0,PORT_C,PIN_1,PORT_C,PIN_2,PORT_C,PIN_3};
//KeypadCol_PORT_PIN col={PORT_C,PIN_4,PORT_C,PIN_5,PORT_C,PIN_6,PORT_C,PIN_7};
void main(){
	LCD_Info lcd={RS_PORT,RS_PIN,RW_PORT,RW_PIN,E_PORT,E_PIN,DATA_PORT};
LCD_VoidInit(&lcd);
//u32 x=1256;
	u8 local_adcRead;
	ADC_ErrStateInit();
	DIO_ErrStateSetGroupDirection(PORT_A,DIO_IN);
	DIO_ErrStateSetGroupDirection(PORT_C,DIO_OUT);

			//DIO_ErrStateSetPortValue(PORT_C,local_adcRead);
			//_delay_ms(500);

	while(1){
		local_adcRead=ADC_ErrStateReadValue(PIN_0);
		LCD_VoidSendInt(local_adcRead,&lcd);

		//LCD_VoidSendChar(' ',&lcd);
_delay_ms(100);
LCD_VoidGoToXY(0,0,&lcd);
	//LCD_VoidSendChar(('1'+48),&lcd);
	//LCD_VoidSendString(" This is String",&lcd);
	//LCD_VoidSendInt(122,&lcd);

	}

}

