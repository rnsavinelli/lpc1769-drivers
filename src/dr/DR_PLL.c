/*
 * DR_PLL.h
 *
 *  Created on: 3 Oct 2019
 *      Author: rnsavinelli
 */

#include "DR_PLL.h"

/* Activates the external oscillator as the input source for the clock and */
/* configures PLL to get an internal clock of 100MHz */

void PLL_Initialize(void)
{
	SCS = SCS_Value;

    /* If Main Oscillator is enabled waits for it to be ready */
	if (SCS_Value & (1 << 5)) {
		while ((SCS & (1<<6)) == 0);
    }

    /* Setup Clock Divider */
	CCLKCFG   = CCLKCFG_Value;

    /* Peripheral Clock Selection */
	PCLKSEL0  = PCLKSEL0_Value;
	PCLKSEL1  = PCLKSEL1_Value;

    /* Clock Source Selection */
	CLKSRCSEL = CLKSRCSEL_Value;

    /* Configuration for PLL0 */
	PLL0CFG   = PLL0CFG_Value;
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

    /* PLL0 Enable */
	PLL0CON   = 0x01;
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

    /* Waits for PLOCK0 */
	while (!(PLL0STAT & (1<<26)));
	
    /* PLL0 Enable and Connect */
	PLL0CON   = 0x03;
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

    /* Waits for PLLC0_STAT and PLLE0_STAT */
	while (!(PLL0STAT & ((1<<25) | (1<<24))));

    /* Configuration for PLL1 */
	PLL1CFG   = PLL1CFG_Value;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

    /* PLL1 Enable */
	PLL1CON   = 0x01;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

    /* Waits for PLOCK1 */
	while (!(PLL1STAT & (1<<10)));

    /* PLL1 Enable and Connect */
	PLL1CON   = 0x03;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

    /* Waits for PLLC1_STAT and PLLE1_STAT */
	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));

    /* Power Control for Peripherals */
	*PCONP     = PCONP_Value;

    /* Clock Output Configuration */
	CLKOUTCFG = CLKOUTCFG_Value;

	/* Flash Access Time Configuration */
	FLASHCFG  = (FLASHCFG & ~0x0000F000) | FLASHCFG_Value;

	return;
}


