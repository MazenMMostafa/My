/*
 * EXTINT2_Private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_2_EXTINT2_PRIVATE_H_
#define MCAL_EXT_INT_INT_2_EXTINT2_PRIVATE_H_
#include "../Common_INT_Reg.h"

#include "../Global_Interrupt_Enable.h"
#include "../../../common/Common_H.h"
#define ISC2 6
#define GICR_INT2_BIT 5
#define GIFR_INT2_BIT 5


typedef enum{
	INT2_OK,
	INT2_PTR_OK,
	INT2_PTR_NULL
}INT2_Err;
#endif /* MCAL_EXT_INT_INT_2_EXTINT2_PRIVATE_H_ */
