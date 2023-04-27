/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Mazen
 */

#ifndef RTOS_STACK__RTOS_RTOS_INTERFACE_H_
#define RTOS_STACK__RTOS_RTOS_INTERFACE_H_
#include "RTOS_Config.h"

void RTOS_VoidStart(void);
u8 RTOS_VoidCreatetask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);
void RTOS_VoidSuspendTask(u8 Copy_u8Priority);
void RTOS_VoidResumeTask(u8 Copy_u8Priority);
void RTOS_VoidDeleteTask(u8 Copy_u8Priority);

#endif /* RTOS_STACK__RTOS_RTOS_INTERFACE_H_ */
