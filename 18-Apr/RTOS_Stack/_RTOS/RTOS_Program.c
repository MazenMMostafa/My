/*
 * RTOS_Program.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mazen
 */


#include "../GIE/GIE.h"
#include "RTOS_Interface.h"
#include "../Timer0/Timer0_Interface.h"

Task_t SystemTasks[TASK_NUM]={{Null}};
void RTOS_VoidStart(void){
	Timer0_VoidSetOCR0(&voidScheduler);
	GIEEnable();
	T0_VoidInit();

}
u8 RTOS_VoidCreatetask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay){
	u8 Local_u8ErrorState= R_CREATED;
	/* check if the required priority empty or used for another task */
	if(SystemTasks[Copy_u8Priority].TaskFun==NULL){
		SystemTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFun=Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].State=TASK_RESUMED; /* Initialize Task State */
		SystemTasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay; /* assign first delay */
	}
	else{
		Local_u8ErrorState= R_Error;
	}
	return Local_u8ErrorState;
}
void RTOS_VoidSuspendTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].State=TASK_SUSPENDED;
}
void RTOS_VoidResumeTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].State=TASK_RESUMED;
}
void RTOS_VoidDeleteTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].TaskFun=Null;
}
static void voidScheduler(void){
	//static u16 Local_u16Tickcounter=0; changed to use first delay
	u8 Local_u8TaskCounter;
	//Local_u16Tickcounter++;
	/* Loop on all tasks to check their priodicity */
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		/* Suspended or Not  */
		if(SystemTasks[Local_u8TaskCounter].State==TASK_RESUMED){
			/* INVOKE THE TASK FUNCTION */
			//if((Local_u16Tickcounter%SystemTasks[Local_u8TaskCounter].Periodicity)==0){
			if(SystemTasks[Local_u8TaskCounter].FirstDelay==0){

				if(SystemTasks[Local_u8TaskCounter].TaskFun!=Null){
					SystemTasks[Local_u8TaskCounter].TaskFun();
					/* Assign the first delay parameter periodicity-1 */
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity-1;
				}
				else
				{
					/* Decrement the first delay */
					SystemTasks[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
		else
		{
			/* Task Suspended Do nothing */
		}
	}
}
