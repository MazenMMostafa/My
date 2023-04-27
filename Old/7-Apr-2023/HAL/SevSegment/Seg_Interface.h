/*
 * 7Seg_Interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Mazen
 */

#ifndef HAL_SEVSEGMENT_SEG_INTERFACE_H_
#define HAL_SEVSEGMENT_SEG_INTERFACE_H_

#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Seg_Config.h"
#include "Sev_Private.h"

SevErrState SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1);
/*	Numbers should be from 0 to 9*/
SevErrState SevSeg_SevErrStateSetNumber(u8 INPUT_NUMBER , SevSeg_info * SevenSegment1);

SevErrState SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End );

SevErrState SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);


#endif /* HAL_SEVSEGMENT_SEG_INTERFACE_H_ */
