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
#include "../MCAL/EXT_INT/Global_Interrupt_Enable.h"
u16 ADC_Value,MilliVolt;
	u32 temp;
	LCD_Info lcd={RS_PORT,RS_PIN,RW_PORT,RW_PIN,E_PORT,E_PIN,DATA_PORT};
		LCD_Line_Info type = {YES,NO};
//Led_info Led={PORT_D,PIN_0,Source_Connection};
void ADCTEST(void);
//KeypadRow_PORT_PIN row={PORT_C,PIN_0,PORT_C,PIN_1,PORT_C,PIN_2,PORT_C,PIN_3};
//KeypadCol_PORT_PIN col={PORT_C,PIN_4,PORT_C,PIN_5,PORT_C,PIN_6,PORT_C,PIN_7};
void main(){

	ADC_ErrStateInit();
DIO_ErrStateSetPinDirection(PORT_D,PIN_0,DIO_OUT);


	EnableGlobalInterrupt();
	while(1){//temp=0;
		//ADC_ErrStateConversionSynch(0,&ADC_Value);
		ADC_ErrStateConversionASynch(0,&ADC_Value,&ADCTEST);
		MilliVolt= (((u32)ADC_Value*5000UL)/256UL);
		temp=MilliVolt/10;
		LCD_VoidInit(&lcd);
		DIO_ErrStateSetPinValue(PORT_D,PIN_0,DIO_HIGH);
		_delay_ms(500);
		DIO_ErrStateSetPinValue(PORT_D,PIN_0,DIO_LOW);
		_delay_ms(500);
		//LCD_VoidSendCommand(0x01,&lcd);
	}

}

void ADCTEST(void){
	LCD_VoidSendInt(temp,&lcd,&type);
	LCD_VoidSendString(" C",&lcd,&type);
	LCD_VoidSendChar('\0',&lcd,&type);
	_delay_ms(500);

}
