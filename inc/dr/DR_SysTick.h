/*
 * DR_SysTick.h
 *
 *  Created on: 22 Sep 2019
 *      Author: rnsavinelli
 */

#ifndef DR_SYSTICK_H_
#define DR_SYSTICK_H_

#include "DR_Variables.h"

#define STCTRL		*( ( __RW uint32_t * ) 0xE000E010UL )
#define STRELOAD	*( ( __RW uint32_t * ) 0xE000E014UL )
#define STCURR		*( ( __RW uint32_t * ) 0xE000E018UL )
#define STCALIB		*( ( __RW uint32_t * ) 0xE000E01CUL )

#define SysTick_CTRL_DISABLE	0	 // Reset value
#define SysTick_CTRL_ENABLE		0x04 // (bin: 100) Enables counter
#define SysTick_CTRL_TICKINT	0x02 // (bin: 010) Enables Interrupt
#define SysTick_CTRL_CLKSOURCE	0x01 // (bin: 001) Selects CPU clock

#define SysTick_CTRL_ENABLE_ALL	0x07 // (bin: 111) Combines the macros declared above

/* Functions */
void SysTick_Initialize(void);
void SysTick_Handler(void);

#endif /* DR_SYSTICK_H_ */
