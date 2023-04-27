/*
 * Watchdog_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Mazen
 */

#include "Watchdog_Interface.h"
void WDT_voidEnable(void)
{
SET_BIT(WDTCR_Reg,WDTCR_WDE);

}
void WDT_voidDisable(void){
WDTCR_Reg=(1<<WDTCR_WDTOE)|(1<<WDTCR_WDE);
WDTCR_Reg=0;
}
WDErr WDT_ErrStateSleep(u8 SleepTime){
if(SleepTime<8){
	WDTCR_Reg&=0b11111000;
	WDTCR_Reg|=SleepTime;
}
else{
	return WDTime_Wrong;
}
return WDTime_OK;
}
