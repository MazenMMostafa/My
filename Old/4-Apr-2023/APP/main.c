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


//Led_info Led={PORT_A,PIN_0,Source_Connection};
/*
 *
 * typedef struct
{
	PORT_Name RS_group;
	PIN_Number RS_pin;
	PORT_Name RW_group;
	PIN_Number RW_pin;
	PORT_Name E_group;
	PIN_Number E_pin;
	PORT_Name Data_group;
}LCD_Info ;
 */
/*
 *
 *
 * typedef struct{
	PORT_Name ROW_PORT1 ;
	PIN_Number ROW_PIN1  ;
	PORT_Name ROW_PORT2 ;
	PIN_Number ROW_PIN2  ;
	PORT_Name ROW_PORT3 ;
	PIN_Number ROW_PIN3  ;
	PORT_Name ROW_PORT4 ;
	PIN_Number ROW_PIN4  ;
}KeypadRow_PORT_PIN;
typedef struct{
	PORT_Name COL_PORT1 ;
	PIN_Number COL_PIN1  ;
	PORT_Name COL_PORT2 ;
	PIN_Number COL_PIN2  ;
	PORT_Name COL_PORT3 ;
	PIN_Number COL_PIN3  ;
	PORT_Name COL_PORT4 ;
	PIN_Number COL_PIN4  ;
}KeypadCol_PORT_PIN;
 */
void main(){
	DIO_ErrStateSetPinDirection(PORT_A,PIN_0,DIO_OUT);
	//DIO_ErrStateSetPinValue(PORT_A,0,DIO_LOW);
	LCD_Info lcd={PORT_B,PIN_0,PORT_B,PIN_1,PORT_B,PIN_2,PORT_A};
	KeypadRow_PORT_PIN row={PORT_C,PIN_0,PORT_C,PIN_1,PORT_C,PIN_2,PORT_C,PIN_3};
	KeypadCol_PORT_PIN col={PORT_C,PIN_4,PORT_C,PIN_5,PORT_C,PIN_6,PORT_C,PIN_7};
		u8 x;
		u8 read;
		LCD_VoidInit(&lcd);
		KP_ErrStateInit(&row,&col);
	Time_0_Init();
	while(1){
		read=KP_ErrStateRead(&row,&col,&x);
		if(read == OK)
		LCD_VoidSendChar(x,&lcd);
	}

}

