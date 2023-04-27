/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Mazen
 */
#include "../HAL/LCD_Driver/LCD_Interface.h"
#include "../MCAL/Global_Interrupt_Enable.h"
#include "../HAL/Keypad_Driver/Keypad_Interface.h"
#include "../MCAL/Timer/Timer2/T2_FASTPWM/T2_FASTPWM_Interface.h"
//u8 Button,Mode=1,Read;
LCD_Line_Info type ={YES,NO};LCD_Line_Info type2 ={NO,YES};
LCD_Info lcd={RS_PORT,RS_PIN,RW_PORT,RW_PIN,E_PORT,E_PIN,DATA_PORT};
KeypadRow_PORT_PIN RPP={KP_ROW_PORT1,KP_ROW_PIN1,KP_ROW_PORT2,KP_ROW_PIN2,KP_ROW_PORT3,KP_ROW_PIN3,KP_ROW_PORT4,KP_ROW_PIN4};
KeypadCol_PORT_PIN CPP={KP_COL_PORT1,KP_COL_PIN1,KP_COL_PORT2,KP_COL_PIN2,KP_COL_PORT3,KP_COL_PIN3,KP_COL_PORT4,KP_COL_PIN4};
//Switch_Info PB ={PORT_D,PIN_2,InternalPullUp};
void main(void){
	u8 Reading,errstate;
	KP_ErrStateInit(&RPP,&CPP);
	EnableGlobalInterrupt();
	LCD_VoidInit(&lcd);
	T2_VoidFPWMInit();

	DIO_ErrStateSetPinDirection(PORT_D,PIN_7,DIO_OUT);
	T2_VoidSetOCR2(0);
	while(1){
		errstate=KP_ErrStateRead(&RPP,&CPP,&Reading);
		if(errstate==OK){

			if(Reading=='0'){
				T2_VoidSetOCR2(0);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=OFF",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='1'){
				//DIO_ErrStateSetPinValue(PORT_D,PIN_7,DIO_IN);
				T2_VoidSetOCR2(246);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=10%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='2'){
				T2_VoidSetOCR2(247);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=20%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='3'){
				T2_VoidSetOCR2(248);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=30%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='4'){
				T2_VoidSetOCR2(249);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=40%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='5'){
				T2_VoidSetOCR2(250);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=50%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='6'){
				T2_VoidSetOCR2(251);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=60%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='7'){
				T2_VoidSetOCR2(252);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=70%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='8'){
				T2_VoidSetOCR2(253);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=80%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='9'){
				T2_VoidSetOCR2(254);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=90%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
			else if(Reading=='+'){
				T2_VoidSetOCR2(255);
				LCD_VoidSendCommand(LCD_ClearDisplay,&lcd);
				LCD_VoidSendString("Motor Speed=100%",&lcd,&type);
				LCD_VoidGoToXY(0,0,&lcd);
			}
		}
	}
}
