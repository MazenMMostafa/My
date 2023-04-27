/*
 * SPI_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_
#include "../../../common/Common_H.h"
#include "SPI_Private.h"

#define Mode LEAD_Sample_Falling

#if Mode==LEAD_Sample_Falling
#define SET_MODE CLEAR_BIT(SPCR_Reg,SPCR_CPOL);\
				  CLEAR_BIT(SPCR_Reg,SPCR_CPHA)

#elif Mode==LEAD_Sample_Rising
#define SET_MODE CLEAR_BIT(SPCR_Reg,SPCR_CPOL);\
				  SET_BIT(SPCR_Reg,SPCR_CPHA)

#elif Mode==LEAD_Setup_Falling
#define SET_MODE SET_BIT(SPCR_Reg,SPCR_CPOL);\
				  CLEAR_BIT(SPCR_Reg,SPCR_CPHA)

#elif Mode==LEAD_Setup_Rising
#define SET_MODE SET_BIT(SPCR_Reg,SPCR_CPOL);\
				  SET_BIT(SPCR_Reg,SPCR_CPHA)
#endif

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
