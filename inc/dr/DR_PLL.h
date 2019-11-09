/*
 * DR_PLL.h
 *
 *  Created on: 3 Oct 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef DR_PLL_H_
#define DR_PLL_H_

#include"DR_Variables.h"

/* Power Control for Peripherals Register (PCONP) */
#define		PCONP		( ( __RW uint32_t * ) 0x400FC0C4UL )
/* A/D converter (ADC) power/clock control bit */
#define 	PCADC	12

/* ***************************************** *
 * FIRST MEMORY ADDRESS FOR PCLKSEL REGISTER *
 * ***************************************** */

/* Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual] */
#define	PCLKSEL	( ( __RW uint32_t * ) 0x400FC1A8UL)
/* PCLKSEL Registers */
#define		PCLKSEL0	(* ( ( __RW uint32_t * ) 0x400FC1A8UL ) )
#define		PCLKSEL1	(* ( ( __RW uint32_t * ) 0x400FC1ACUL ) )

/* ***************************************** *
 * ****** System and Clock Registers ******* *
 * ***************************************** */

/* System Control and Status Register */
#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
/* CPU Clock Configuration Register */
#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
/* Peripheral Clock Selection Register */
#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
/* Clock Output Configuration Register */
#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
/* Flash Accelerator Configuration Register */
#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

/* ***************************************** *
 * ********* PPL0/PLL1 REGISTERS *********** *
 * ***************************************** */

/* MAIN PLL */
/* PLL0 Control Register: */
#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
/* PLL0 Configuration Register: */
#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
/* PLL0 Status Register: */
#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
/* PLL0 Feed Register */
#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)

/* USB PLL */
/* PLL1 Control Register: */
#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
/* PLL1 Configuration Register: */
#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
/* PLL0 Status Register: */
#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
/* PLL1 Feed Register */
#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

/* ***************************************** *
 * **** MACROS FOR IMPROVED READABILITY **** *
 * ***************************************** */

/* System Control and Status, and FLASHCFG */
#define		SCS			DIR_SCS[0]
#define 	FLASHCFG	DIR_FLASHCFG[0]

/* System Clock Control Registers Macros */
#define		CCLKCFG		DIR_CCLKCFG[0]
#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
#define		CLKOUTCFG	DIR_CLKOUTCFG[0]

/* PLL0 MACROS */
#define		PLL0CON		DIR_PLL0CON[0]
#define		PLL0CFG		DIR_PLL0CFG[0]
#define		PLL0STAT	DIR_PLL0STAT[0]
#define		PLL0FEED	DIR_PLL0FEED[0]

/* PLL1 MACROS */
#define		PLL1CON		DIR_PLL1CON[0]
#define		PLL1CFG		DIR_PLL1CFG[0]
#define		PLL1STAT	DIR_PLL1STAT[0]
#define		PLL1FEED	DIR_PLL1FEED[0]

/* PLL Configuration Macros */
#define CLOCK_SETUP_Value 	    1
#define SCS_Value				0x00000020
#define CLKSRCSEL_Value         0x00000001
#define PLL0_SETUP_Value        1
#define PLL0CFG_Value           0x00050063
#define PLL1_SETUP_Value        1
#define PLL1CFG_Value           0x00000023
#define CCLKCFG_Value           0x00000003
#define USBCLKCFG_Value         0x00000000
#define PCLKSEL0_Value          0x00000000
#define PCLKSEL1_Value          0x00000000
#define PCONP_Value             0x042887DE
#define CLKOUTCFG_Value         0x00000000
#define FLASHCFG_Value			0x00004000

/* Functions */
void PLL_Initialize(void);

#endif /* DR_PLL_H_ */
