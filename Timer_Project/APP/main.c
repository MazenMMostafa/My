/*
 * main.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Mazen
 */
#include "../MCAL/SPI/SPI_Interface.h"
#include "../HAL/LCD_Driver/LCD_Interface.h"
#include "../MCAL/Global_Interrupt_Enable.h"
#include "../MCAL/Timer/Timer0/Timer0_Interface.h"
#include "../HAL/Switch/Switch_Interface.h"
#include "../MCAL/EXT_INT/INT_0/EXTINT0_Interface.h"
#include "../HAL/Keypad_Driver/Keypad_Interface.h"
u8 Button,Mode=1,Read;
LCD_Line_Info type ={YES,NO};LCD_Line_Info type2 ={NO,YES};
LCD_Info lcd={RS_PORT,RS_PIN,RW_PORT,RW_PIN,E_PORT,E_PIN,DATA_PORT};
KeypadRow_PORT_PIN RPP={KP_ROW_PORT1,KP_ROW_PIN1,KP_ROW_PORT2,KP_ROW_PIN2,KP_ROW_PORT3,KP_ROW_PIN3,KP_ROW_PORT4,KP_ROW_PIN4};
KeypadCol_PORT_PIN CPP={KP_COL_PORT1,KP_COL_PIN1,KP_COL_PORT2,KP_COL_PIN2,KP_COL_PORT3,KP_COL_PIN3,KP_COL_PORT4,KP_COL_PIN4};
s8  SSec1,SSec2,SMin1,SMin2,SHour1,SHour2,ct,SwitchCounter;
//Switch_Info PB ={PORT_D,PIN_2,InternalPullUp};

void TimerCountUpDown(void);
void TimerModeSwitch(void);
void main()
{
	EnableGlobalInterrupt();
	T0_VoidInit();
	LCD_VoidInit(&lcd);
	DIO_ErrStateSetPinDirection(PORT_D,PIN_1,DIO_OUT);
	/*01 34 67*/
	LCD_VoidSendString("00:00:00",&lcd,&type2);
	Timer0_u8SetCallBack(TimerCountUpDown);
	INT0_VoidSETINT0();
	INT0_SetCallBack(TimerModeSwitch);
	KP_ErrStateInit(&RPP,&CPP);
	//SW_SwitchErrStateGetState(&PB,&Button);
	while(1){
		KP_ErrStateRead(&RPP,&CPP,&Read);
		if(Read=='C'){
			//LCD_VoidSendCommand(0x10,&lcd);
			Read=0;
			ct--;
			if(ct==-1){
				ct=7;
			}
			LCD_VoidGoToXY(ct,0,&lcd);
			Read=0;
			SwitchCounter=ct;

		}
		else if(Read=='='){
			ct++;
			LCD_VoidGoToXY(ct,0,&lcd);
			if(ct==7){
				ct=0;
			}
			Read=0;
			SwitchCounter=ct;
		}
		/*else {
			switch(ct){
			case 1:
				SSec1=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 2:
				SSec2=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 4:
				SMin1=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 5:
				SMin2=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 7:
				SHour1=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 8:
				SHour2=Read-48;
				LCD_VoidSendChar(Read,&lcd,&type);
				Read=0;
				break;
			case 9:
				ct=0;
				break;


			}

		}*/
	}

}
// EXT0 Work
void TimerModeSwitch(void){
	DIO_ErrStateSetPinDirection(PORT_D,PIN_1,DIO_OUT);
	DIO_ErrStateSetPinValue(PORT_D,PIN_1,DIO_HIGH);
	if(Button==0){
		Mode++;

	}
	if(Mode==0){
		DIO_ErrStateSetPinValue(PORT_D,PIN_1,DIO_HIGH);
	}
	else if(Mode==1){
		DIO_ErrStateSetPinValue(PORT_D,PIN_1,DIO_LOW);
	}
	else if(Mode==2){
		DIO_ErrStateSetPinValue(PORT_D,PIN_1,DIO_HIGH);
		//_delay_ms(50);
	}
	else
		Mode=0;
	if(Read!='='&&Read!='C'){
		LCD_VoidSendChar(Read,&lcd,&type);
		switch(ct){
		case 1:
			SSec1=Read-48;

			Read=0;
			break;
		case 2:
			SSec2=Read-48;

			Read=0;
			break;
		case 4:
			SMin1=Read-48;
			Read=0;
			break;
		case 5:
			SMin2=Read-48;
			Read=0;
			break;
		case 7:
			SHour1=Read-48;
			Read=0;
			break;
		case 8:
			SHour2=Read-48;
			Read=0;
			break;
		case 9:
			ct=0;
			break;


		}
		Read=0;
	}
}
// T0 CTC Work
void TimerCountUpDown(void)
{

	static u8 Sec1,Sec2,Min1,Min2,Hour1,Hour2;
	if(Mode==0){
		Sec1= SSec1;
		Sec2= SSec2;
		Min1= SMin1;
		Min2= SMin2;
		Hour1=SHour1;
		Hour2=SHour2;
	}
	else if(Mode==1){
		Sec1++;
		if(Sec1==9){
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(9,&lcd,&type);
		}
		if(Sec1<=9){
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
		}
		if((Sec1>=10)&&(Sec2<5)){
			Sec2++;
			Sec1=0;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);


		}
		if(Sec1>=10&&Sec2>=5&&Min1<=9){
			Sec1=0;
			Sec2=0;
			Min1++;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);


		}
		if(Sec1>=10&&Sec2>=5&&Min1>9&&Min2<=5){

			Min1=0;
			Sec1=0;
			Sec2=0;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
			LCD_VoidGoToXY(3,0,&lcd);
			LCD_VoidSendInt(Min2,&lcd,&type);
			Min2++;
		}
		if(Sec1>=10&&Sec2>=5&&Min1>=9&&Min2>=5&&Hour1<=9){

			Min2=0;
			Min1=0;
			Sec1=0;
			Sec2=0;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
			LCD_VoidGoToXY(3,0,&lcd);
			LCD_VoidSendInt(Min2,&lcd,&type);
			LCD_VoidGoToXY(1,0,&lcd);
			LCD_VoidSendInt(Hour1,&lcd,&type);
			Hour1++;
		}
		if(Sec1>=10&&Sec2>=5&&Min1>=9&&Min2>=5&&Hour1>=9&&Hour2<=5){
			Hour1=0;
			Min2=0;
			Min1=0;
			Sec1=0;
			Sec2=0;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
			LCD_VoidGoToXY(3,0,&lcd);
			LCD_VoidSendInt(Min2,&lcd,&type);
			LCD_VoidGoToXY(1,0,&lcd);
			LCD_VoidSendInt(Hour1,&lcd,&type);
			LCD_VoidGoToXY(0,0,&lcd);
			LCD_VoidSendInt(Hour2,&lcd,&type);
			Hour2++;

		}
		if(Sec1>=10&&Sec2>=5&&Min1>=9&&Min2>=5&&Hour1>=9&&Hour2>=5){
			Hour2=0;
			Hour1=0;
			Min2=0;
			Min1=0;
			Sec1=0;
			Sec2=0;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
			LCD_VoidGoToXY(3,0,&lcd);
			LCD_VoidSendInt(Min2,&lcd,&type);
			LCD_VoidGoToXY(1,0,&lcd);
			LCD_VoidSendInt(Hour1,&lcd,&type);
			LCD_VoidGoToXY(0,0,&lcd);
			LCD_VoidSendInt(Hour2,&lcd,&type);
		}
	}

	else if(Button==2)
	{
		Sec1--;
		if(Sec1>=0){
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
		}
		if((Sec1==0)&&(Sec2>=0)){
			Sec1=9;
			Sec2--;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
		}
		if((Sec1==0)&&(Sec2==0)&&(Min1>=0)){
			Sec1=9;
			Sec2=9;
			Min1--;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
		}
		if((Sec1==0)&&(Sec2==0)&&(Min1==0)&&(Min2>=0)){
			Sec1=9;
			Sec2=9;
			Min1=9;
			Min2--;
			LCD_VoidGoToXY(7,0,&lcd);
			LCD_VoidSendInt(Sec1,&lcd,&type);
			LCD_VoidGoToXY(6,0,&lcd);
			LCD_VoidSendInt(Sec2,&lcd,&type);
			LCD_VoidGoToXY(4,0,&lcd);
			LCD_VoidSendInt(Min1,&lcd,&type);
			LCD_VoidGoToXY(3,0,&lcd);
			LCD_VoidSendInt(Min2,&lcd,&type);
		}

		//(SHour2==0)&&(SHour1==0)&&(SMin2==0)&&(SMin1==0)&&(SSec2==0)&&(SSec1==0)


	}
}
