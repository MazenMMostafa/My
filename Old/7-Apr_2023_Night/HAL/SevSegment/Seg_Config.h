/*
 * 7Seg_Config.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Mazen
 */

#ifndef HAL_SEVSEGMENT_SEG_PRIVATE_H_
#define HAL_SEVSEGMENT_SEG_PRIVATE_H_
#include "../../MCAL/DIO/DIO_Interface.h"
typedef struct
{
	u8 SevSeg_Type       ;
	u8 SevSeg_Group      ;
	u8 SevSeg_EnablePort ;
	u8 SevSeg_EnablePin  ;
}SevSeg_info;


#endif /* HAL_SEVSEGMENT_SEG_CONFIG_H_ */
