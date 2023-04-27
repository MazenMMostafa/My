/*
 * Watchdog_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_WATCHDOG_WATCHDOG_INTERFACE_H_
#define MCAL_TIMER_WATCHDOG_WATCHDOG_INTERFACE_H_
#include "Watchdog_Private.h"

void WDT_voidEnable(void);
void WDT_voidDisable(void);
WDErr WDT_ErrStateSleep(u8 SleepTime);



#endif /* MCAL_TIMER_WATCHDOG_WATCHDOG_INTERFACE_H_ */
