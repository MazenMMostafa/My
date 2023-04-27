/*
 * LCD_Program.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Mazen
 */
#include"../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include <stdlib.h>

void LCD_VoidSendCommand(u8 Local_Command,LCD_Info *lcd){
	/*RS->LOw*/
	DIO_ErrStateSetPinValue(lcd->RS_group,lcd->RS_pin,DIO_LOW);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(lcd->RW_group,lcd->RW_pin,DIO_LOW);
	/*Group = Command*/
	DIO_ErrStateSetPortValue(lcd->Data_group,Local_Command);
	/*Enable*/
	DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_HIGH);
	_delay_ms(1);
	DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_LOW);
	_delay_ms(1);
	if(Local_Command==0x01)
		LCD_VoidGoToXY(0,0,lcd);
}

u8 LCD_VoidSendChar(u8 Local_Char,LCD_Info *lcd,LCD_Line_Info *Type)
{
	static u8 SwitchingCounter;
	static u8 SecondLineCounter,FirstLineCounter;

	if(Type->OneLine==NO&&Type->TwoLines==YES){
		if(SwitchingCounter<16){
			LCD_VoidGoToXY(FirstLineCounter,0,lcd);
			/*RS->LOw*/
			DIO_ErrStateSetPinValue(lcd->RS_group,lcd->RS_pin,DIO_HIGH);
			/*RW-> LOW*/
			DIO_ErrStateSetPinValue(lcd->RW_group,lcd->RW_pin,DIO_LOW);
			/*Group = Command*/
			DIO_ErrStateSetPortValue(lcd->Data_group,Local_Char);
			/*Enable*/
			DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_HIGH);
			_delay_ms(1);
			DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_LOW);
			_delay_ms(1);
			SwitchingCounter++;
			FirstLineCounter++;
		}
		else if(SwitchingCounter>15&&SwitchingCounter<32){
			LCD_VoidGoToXY(SecondLineCounter,1,lcd);
			/*RS->LOw*/
			DIO_ErrStateSetPinValue(lcd->RS_group,lcd->RS_pin,DIO_HIGH);
			/*RW-> LOW*/
			DIO_ErrStateSetPinValue(lcd->RW_group,lcd->RW_pin,DIO_LOW);
			/*Group = Command*/
			DIO_ErrStateSetPortValue(lcd->Data_group,Local_Char);
			/*Enable*/
			DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_HIGH);
			_delay_ms(1);
			DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_LOW);
			_delay_ms(1);
			SwitchingCounter++;
			SecondLineCounter++;
		}
		else{
			SwitchingCounter=0;
			FirstLineCounter=0;
			SecondLineCounter=0;
			//LCD_VoidSendCommand(0x01,lcd);
		}
	}
	else if(Type->OneLine==YES&&Type->TwoLines==NO){
			if(SwitchingCounter<16&&Local_Char!='\0'){
				//LCD_VoidGoToXY(0,0,lcd);
				/*RS->LOw*/
				DIO_ErrStateSetPinValue(lcd->RS_group,lcd->RS_pin,DIO_HIGH);
				/*RW-> LOW*/
				DIO_ErrStateSetPinValue(lcd->RW_group,lcd->RW_pin,DIO_LOW);
				/*Group = Command*/
				DIO_ErrStateSetPortValue(lcd->Data_group,Local_Char);
				/*Enable*/
				DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_HIGH);
				_delay_ms(1);
				DIO_ErrStateSetPinValue(lcd->E_group,lcd->E_pin,DIO_LOW);
				_delay_ms(1);
				SwitchingCounter++;
				FirstLineCounter++;
			}
			else{
				FirstLineCounter=0;
				SwitchingCounter=0;
				//LCD_VoidSendCommand(0x01,lcd);
			}
		}
	return 0;

}
void LCD_VoidInit(LCD_Info *lcd){
	/*Set Directions*/
	DIO_ErrStateSetPinDirection(lcd->RS_group,lcd->RS_pin,DIO_OUT);
	DIO_ErrStateSetPinDirection(lcd->RW_group,lcd->RW_pin,DIO_OUT);
	DIO_ErrStateSetPinDirection(lcd->E_group,lcd->E_pin,DIO_OUT);
	DIO_ErrStateSetGroupDirection(lcd->Data_group,0xFF);
	/*Wait more than 30 ms*/
	_delay_ms(40);
	/*Sent function set*/
	LCD_VoidSendCommand(LCD_Set8Bit2Line5x8,lcd);
	/*WAIT 39us*/
	_delay_ms(1);
	LCD_VoidSendCommand(LCD_CursorON,lcd);
	_delay_ms(1);
	/*LCD Clear Display*/
	LCD_VoidSendCommand(LCD_ClearDisplay,lcd);
	_delay_ms(1);

}

void LCD_VoidSendString(u8 *Address_String,LCD_Info *lcd,LCD_Line_Info *Type){

	while (*Address_String != '\0') {
		// Send the current character to the LCD
		LCD_VoidSendChar(*Address_String, lcd,Type);
		Address_String++; // Move to the next character
	}
}
void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition, LCD_Info *lcd) {
	u8 Address = 0;
	/* Calculate the DDRAM address based on the row and column */
	if(Local_YPosition == 0) {
		Address = LCD_FirstLine + Local_XPosition;
	} else {
		Address = LCD_SecoundLine + Local_XPosition;
	}
	/* Send the command to set the DDRAM address */
	LCD_VoidSendCommand(LCD_SetAddressDDRAM | Address, lcd);
}

void LCD_VoidSpecialCharacter(u8 *pattern,u8 location, LCD_Info *lcd,LCD_Line_Info *Type){
	LCD_VoidSendCommand(LCD_SetAddressCGRAM+(location*8),lcd);
	/* Sending the bitmap to CGRAM */
	for(u8 i=0;i<8;i++){
		LCD_VoidSendChar(pattern[i],lcd,Type);
	}
	/*	Send the cursor to DDRAM + choose location */
	LCD_VoidGoToXY(1,1,lcd);
	LCD_VoidSendChar(location,lcd,Type);
}
void LCD_VoidSendInt(u32 Recieved_Number,LCD_Info *lcd,LCD_Line_Info *Type){
	u8 NumAsString[LCD_StringMax]={' '};
	s32 LCD_StringCounter=0,FORCOUNTER;
	u8 temp,Err=1;

	if(Recieved_Number==0){
		LCD_VoidSendChar('0',lcd,Type);
	}
	else{
		while(Recieved_Number!=0)
		{
			temp=Recieved_Number%10;
			Recieved_Number=Recieved_Number-temp;
			NumAsString[LCD_StringCounter]=temp;
			Recieved_Number=Recieved_Number/10;
			LCD_StringCounter++;

		}
	}
	for(FORCOUNTER=(LCD_StringCounter-1);FORCOUNTER>=0;FORCOUNTER--){
		Err=LCD_VoidSendChar((NumAsString[FORCOUNTER]+48),lcd,Type);

	}
	//LCD_VoidSendChar('\0',lcd,Type);

}
