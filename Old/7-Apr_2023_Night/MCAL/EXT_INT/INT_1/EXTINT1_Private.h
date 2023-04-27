/*
 * EXTINT1_Private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mazen
 */

#ifndef MCAL_EXT_INT_INT_1_EXTINT1_PRIVATE_H_
#define MCAL_EXT_INT_INT_1_EXTINT1_PRIVATE_H_

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
#define ISC10 2
#define ISC11 3

#define GIFR_INT1_BIT 7
#define GICR_INT1_BIT 7

typedef enum{
	INT1_LowLevel,
	INT1_AnyLogicalChange,
	INT1_FallingEdge,
	INT1_RisingEdge
}INT1_Type;

typedef enum{
	INT1_OK,
	INT1_PTR_OK,
	INT1_PTR_NULL
}INT1_Err;

#endif /* MCAL_EXT_INT_INT_1_EXTINT1_PRIVATE_H_ */
