/*
 * bit-math.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mazen
 */
	/*functions like macro */
// Setting specific bit to 1
#define SET_BIT(Reg,Bit) Reg|=(1<<Bit)
// Setting specific bit to 0
#define CLEAR_BIT(Reg,Bit) Reg&=~(1<<Bit)
// changing specific bit from 0 to 1 vice versa
#define TOGGLE_BIT(Reg,Bit) Reg^=(1<<Bit)
// Read specific bit value if 0 or 1 to be added in Val without changing the register value
#define GET_BIT(Reg,Bit) (Reg>>Bit)&1
