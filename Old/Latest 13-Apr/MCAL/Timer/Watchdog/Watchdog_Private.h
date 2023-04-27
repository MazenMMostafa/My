/*
 * Watchdog_Private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_WATCHDOG_WATCHDOG_PRIVATE_H_
#define MCAL_TIMER_WATCHDOG_WATCHDOG_PRIVATE_H_
#include "../../DIO/DIO_Interface.h"
#include "../../../common/Common_H.h"
#include "../../Global_Interrupt_Enable.h"

#define WDTCR_Reg (*(volatile u8*)0x41)

#define WDTCR_WDTOE 4
#define WDTCR_WDE 3

typedef enum{
	WDTime_OK,
	WDTime_Wrong
}WDErr;
#endif /* MCAL_TIMER_WATCHDOG_WATCHDOG_PRIVATE_H_ */
