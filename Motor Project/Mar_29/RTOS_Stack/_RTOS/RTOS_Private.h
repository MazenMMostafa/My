/*
 * RTOS_Private.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Mazen
 */

#ifndef RTOS_STACK__RTOS_RTOS_PRIVATE_H_
#define RTOS_STACK__RTOS_RTOS_PRIVATE_H_
#include "../../common/Common_H.h"
typedef struct{
u16 Periodicity;
void(*TaskFun)(void);
u8 State;
u16 FirstDelay;
}Task_t;
static void voidScheduler(void);

#define TASK_RESUMED 0
#define TASK_SUSPENDED 1
typedef enum{
	R_CREATED,
	R_Error
}RTOS_ErrStat;

#endif /* RTOS_STACK__RTOS_RTOS_PRIVATE_H_ */
