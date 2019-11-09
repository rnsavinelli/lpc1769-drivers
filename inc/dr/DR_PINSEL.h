/*
 * DR_PINSEL.h
 *
 *  Created on: 26 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef DR_PINSEL_H_
#define DR_PINSEL_H_

#include "DR_Variables.h"

/* **************************************** *
 * FIRST MEMORY ADDRESS FOR PINSEL REGISTER *
 * **************************************** */
#define PINSEL		( ( __RW uint32_t * ) 0x4002C000 )

/* MACROS FOR SIMPLER PINSEL ADRESS MANIPULATION */
#define PINSEL0 	PINSEL[0]
#define PINSEL1 	PINSEL[1]
#define PINSEL2 	PINSEL[2]
#define PINSEL3 	PINSEL[3]
#define PINSEL4 	PINSEL[4]
/* PINSEL5 IS NOT USED THEREFORE NOT DEFINED */
/* PINSEL6 IS NOT USED THEREFORE NOT DEFINED */
#define PINSEL7 	PINSEL[7]
/* PINSEL8 IS NOT USED THEREFORE NOT DEFINED */
#define PINSEL9 	PINSEL[9]
/* Note that this nomenclature works because of how
 * PINSEL was first declared. */

/* PINSEL register configuration values */
#define PINSEL_GPIO	0
#define PINSEL_ALT1 1
#define PINSEL_ALT2 2
#define PINSEL_ALT3 3

void SetPINSEL (uint8_t port, uint8_t pin, uint8_t function);

#endif /* DR_PINSEL_H_ */
