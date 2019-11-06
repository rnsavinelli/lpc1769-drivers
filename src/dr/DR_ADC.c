/*
 * DR_ADC.c
 *
 *  Created on: 6 Nov 2019
 *      Author: rnsavinelli
 */

#include "DR_ADC.h"
#include "DR_LPC1769.h"
#include "DR_PINSEL.h"

void ADC_Initialize(void) {
	/* Powers on ADC converter peripheral */
	*PCONP |= (1 << 12);
	/* Sets ADC clock to be 25MHz */
	PCLKSEL0 &= ~(0x03 << 24);
	/* Sets clock divider to 1 to sample at 200kHz*/
	AD0CR |= 0x00000100;

	/* Pin/Channel configuration:
	 * in this example I use channel 5 from the ADC */
	SetPINSEL(ADC0_5, PINSEL_ALT3); /* enables channel 5 pin */
	AD0INTEN = 0x20; /* enables only ch5 interruptions */
	AD0CR |= 0x20; /* selects channel 5 */

	/* The A/D converter becomes operational */
	AD0CR |= (1 << 21);
	/* Lets the A/D converter sample with configurations
	 * BURST = 1 and START = 000 */
	AD0CR &= ~(0x07 << 24);
	AD0CR |= (1 << 16);

	return;
}

void DAC_Initialize(void) {
	/* Pin/Channel configuration: */
	PCLKSEL0 &= ~(0x03 << 24);
	/* enables DAC0 pin */
	SetPINSEL(DAC0, PINSEL_ALT2);
	/* Configures the D/A converter with:
	 * double-buffering disabled (DBLBUF_ENA = 0) and
	 * time-out counter operation disabled (CNT_ENA = 0). */
	DACCTRL &= ~(0x03 << 1);

	return;
}

