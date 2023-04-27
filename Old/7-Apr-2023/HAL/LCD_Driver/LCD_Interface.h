/*
 * LCD_Interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Mazen
 */
#ifndef HAL_LCD_DRIVER_LCD_INTERFACE_H_
#define HAL_LCD_DRIVER_LCD_INTERFACE_H_
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_Register.h"
#include "../../common/Definition.h"
#include <util/delay.h>
void LCD_VoidSendCommand(u8 Local_Command,LCD_Info *lcd);
u8 LCD_VoidSendChar(u8 Local_Char,LCD_Info *lcd);
u8 LCD_VoidSendCharRepeat(u8 Local_Char,LCD_Info *lcd);
void LCD_VoidInit(LCD_Info *lcd);
void LCD_VoidSendString(u8 *Address_String,LCD_Info *lcd);
void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition, LCD_Info *lcd);
void LCD_VoidSpecialCharacter(u8 *pattern,u8 location, LCD_Info *lcd);
void LCD_VoidSendInt(u32 Recieved_Number,LCD_Info *lcd);
#endif /* HAL_LCD_DRIVER_LCD_INTERFACE_H_ */
