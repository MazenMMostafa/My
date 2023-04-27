/*
 * EXTINT0_Private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_0_EXTINT0_PRIVATE_H_
#define MCAL_EXT_INT_INT_0_EXTINT0_PRIVATE_H_
#include "../Common_INT_Reg.h"
#include "../../DIO/DIO_Interface.h"
#include "../../../common/Common_H.h"

/**
ISC01 ISC00 	Description
 	0 0 		The low level of INT0 generates an interrupt request.
	0 1 		Any logical change on INT0 generates an interrupt request.
	1 0			The falling edge of INT0 generates an interrupt request.
	1 1			The rising edge of INT0 generates an interrupt request.
 */
/*
 * 7   6   5   4    3    2     1     0
   SE SM2 SM1 SM0 ISC11 ISC10 ISC01 ISC00 MCUCR
 */
#define ISC00 0
#define ISC01 1
#define GIFR_INT0_BIT 6
#define GICR_INT0_BIT 6


typedef enum{
	INT0_LowLevel,
	INT0_AnyLogicalChange,
	INT0_FallingEdge,
	INT0_RisingEdge
}INT0_Type;

typedef enum{
	INT0_OK,
	INT0_PTR_OK,
	INT0_PTR_NULL
}INT0_Err;

#endif /* MCAL_EXT_INT_INT_0_EXTINT0_PRIVATE_H_ */
