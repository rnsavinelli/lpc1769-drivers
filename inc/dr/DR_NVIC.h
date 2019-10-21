/*
 * DR_NVIC.h
 *
 *  Created on: 5 Oct 2019
 *      Author: rnsavinelli
 */

#ifndef DR_NVIC_H_
#define DR_NVIC_H_

#include "DR_Variables.h"
#include "DR_Keyboard.h"

/* ********************************* *
 * ****** NVIC REGISTER MAP ******** *
 * ********************************* */

/* Interrupt Set-Enable Registers */
#define 	ISER 		( ( __RW uint32_t * ) 0xE000E100UL )

#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

/* I only listed the interrupts I'll use - All the interrupts
 * are listed on page 79 of the manual (UM10360.pdf) */
/* WARNING: THIS ONES ONLY CORRESPOND TO ISER0 AND ARE
 * USED TO ENABLE THIS PARTICULAR REGISTERS */
#define		ISE_EINT0		ISER[0] |= (1 <<  18)
#define		ISE_EINT1		ISER[0] |= (1 <<  19)
#define		ISE_EINT2		ISER[0] |= (1 <<  20)
#define		ISE_EINT3		ISER[0] |= (1 <<  21)
#define		ISE_ADC			ISER[0] |= (1 <<  22)

/* Interrupt Clear-Enable Registers */
#define		ICER		( ( __RW uint32_t * ) 0xE000E180UL )

#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

/* I only listed the interrupts I'll use - All the interrupts
 * are listed on page 81 of the manual (UM10360.pdf) */
/* WARNING: THIS ONES ONLY CORRESPOND TO ICER0 AND ARE
 * USED TO DISABLE THIS PARTICULAR REGISTERS */
#define		ICE_EINT0		ICER[0] |= (1 <<  18)
#define		ICE_EINT1		ICER[0] |= (1 <<  19)
#define		ICE_EINT2		ICER[0] |= (1 <<  20)
#define		ICE_EINT3		ICER[0] |= (1 <<  21)
#define		ICE_ADC			ICER[0] |= (1 <<  22)

/* Interrupt Set-Enable/Clear-Enable Register 0 register bits */
#define NVIC_WDT			0
#define	NVIC_TIM0			1
#define	NVIC_TIM1			2
#define NVIC_TIM2			3
#define NVIC_TIM3			4
#define NVIC_UART0			5
#define NVIC_UART1			6
#define NVIC_UART2			7
#define NVIC_UART3			8
#define NVIC_PWM			9
#define NVIC_I2C0			10
#define NVIC_I2C1			11
#define NVIC_I2C2			12
#define NVIC_SPI			13
#define NVIC_SSP0			14
#define NVIC_SSP1			15
#define NVIC_PLL0			16
#define NVIC_RTC			17
#define NVIC_EINT0			18
#define	NVIC_EINT1			19
#define	NVIC_EINT2			20
#define NVIC_EINT3			21
#define NVIC_ADC			22
#define	NVIC_BOD			23
#define NVIC_USB			24
#define NVIC_CAN			25
#define NVIC_DMA			26
#define NVIC_I2S			27
#define NVIC_ENET			28
#define NVIC_RIT			29
#define NVIC_MCPWM			30
#define NVIC_QEI			31

/* External Interrupt Flag Register */
#define		EXTINT			( * ( (__RW uint32_t  * ) 0x400FC140UL ) )
/* External Interrupt Mode Register */
#define		EXTMODE 		( * ( (__RW uint32_t  * ) 0x400FC148UL ) )
/* External Interrupt Polarity Register */
#define		EXTPOLAR        ( * ( (__RW uint32_t  * ) 0x400FC14CUL ) )

/* *********************************************** *
 * ******* NVIC_EINT_ENABLE / DISABLE ONLY ******* *
 * *********************************************** */
/* EXTERNAL INTERRUPTION MODES */
#define 	EXT_MODE_LEVEL 	0
#define 	EXT_MODE_EDGE 	1

/* Low-active or falling-edge sensitive */
#define		EXT_LEVEL_LOW		0
#define		EXT_EDGE_FALLING	0

#define 	EXT_LEVEL_HIGH		1
#define		EXT_EDGE_RISING		1

/* *************************************** *
 * ****** Functions and variables ******** *
 * *************************************** */

extern uint8_t flag_EXTINT0;
extern uint8_t flag_EXTINT1;
extern uint8_t flag_EXTINT2;
extern uint8_t flag_EXTINT3;

#define NOT_INTERRUPTED	0
#define INTERRUPTED		1

/* Extensible configuration for EINTs */
void NVIC_EINT_Enable(uint8_t interrupt, uint8_t mode, uint8_t polarity);

/* General NVIC enabling */
void NVIC_Enable(uint8_t interrupt);
void NVIC_Disable(uint8_t interrupt);

#endif /* DR_NVIC_H_ */
