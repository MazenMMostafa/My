/*
 * Timer0_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mazen
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_
#include "Timer0_Private.h"
#define T0_Type T0_CTC

#define T0_SetPrescaler  T0_Presc_8
/// Tick Time = Presc/SysFreq
//CTC by3ml clear lel time 3nd w2t el OCR0 el bt7ddo
/*
 * Steps :
 * 1- Tick time=Presc/SysFreq
 * 2- shof lw el tick time bysawy el w2t el enta 3yzo wla la2
 * 3- lw la2 bn5tar rkm y2bl el esma 3la el time el enta 3yzo
 * example lw enta msln 1000000 us momken n5tar OCR0=250
 * yb2a kda el htcount 4000 mra yb2a 1 sec up
 *
 */

#endif /* MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_ */
