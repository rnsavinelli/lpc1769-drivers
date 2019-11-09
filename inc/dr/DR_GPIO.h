/*
 * DR_GPIO.h
 *
 *  Created on: 26 Sep 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef DR_GPIO_H_
#define DR_GPIO_H_

#include "DR_Variables.h"

/* ********************************* *
 * FISRT MEMORY ADDRESS FOR PIN MODE *
 * ********************************* */
#define PINMODE			( ( __RW uint32_t * ) 0x4002C040UL )

/* MACROS FOR SIMPLER PINMODE ADRESS MANIPULATION */
#define PINMODE0		PINMODE[0]
#define PINMODE1		PINMODE[1]
#define PINMODE2		PINMODE[2]
#define PINMODE3		PINMODE[3]
#define PINMODE4		PINMODE[4]
/* PINMODE5 IS NOT USED THEREFORE NOT DEFINED */
/* PINMODE6 IS NOT USED THEREFORE NOT DEFINED */
#define PINMODE7		PINMODE[7]
/* PINSEL8 IS NOT USED THEREFORE NOT DEFINED */
#define PINMODE9		PINMODE[9]
/* Note that this nomenclature works because of how
 * PINMODE was first declared */

/* ******************************************** *
 * FIRST MEMORY ADDRESS FOR OPEN DRAIN PIN MODE *
 * ******************************************** */
#define PINMODE_OD		( ( __RW uint32_t * )  0x4002C068UL )

/* MACROS FOR SIMPLER PINMODE_OD ADRESS MANIPULATION */
#define PINMODE_OD0		PINMODE_OD[0]
#define PINMODE_OD1		PINMODE_OD[1]
#define PINMODE_OD2		PINMODE_OD[2]
#define PINMODE_OD3		PINMODE_OD[3]
#define PINMODE_OD4		PINMODE_OD[4]
/* Note that this nomenclature works because of how
 * PINMODE_OD was first declared */

/* ******************************************** *
 * FIRST MEMORY ADDRESS FOR GPIO CONFIGURATIONS *
 * ******************************************** */
#define GPIO  		( ( __RW uint32_t * )  0x2009C000UL )

/* MACROS FOR SIMPLER GPIO ADRESS MANIPULATION */
#define FIO0DIR		GPIO[0 + 0 * 8]
#define FIO0MASK	GPIO[4 + 0 * 8]
#define FIO0PIN		GPIO[5 + 0 * 8]
#define FIO0SET		GPIO[6 + 0 * 8]
#define FIO0CLR		GPIO[7 + 0 * 8]

#define FIO1DIR		GPIO[0 + 1 * 8]
#define FIO1MASK	GPIO[4 + 1 * 8]
#define FIO1PIN		GPIO[5 + 1 * 8]
#define FIO1SET		GPIO[6 + 1 * 8]
#define FIO1CLR		GPIO[7 + 1 * 8]

#define FIO2DIR		GPIO[0 + 2 * 8]
#define FIO2MASK	GPIO[4 + 2 * 8]
#define FIO2PIN		GPIO[5 + 2 * 8]
#define FIO2SET		GPIO[6 + 2 * 8]
#define FIO2CLR		GPIO[7 + 2 * 8]

#define FIO3DIR		GPIO[0 + 3 * 8]
#define FIO3MASK	GPIO[4 + 3 * 8]
#define FIO3PIN		GPIO[5 + 3 * 8]
#define FIO3SET		GPIO[6 + 3 * 8]
#define FIO3CLR		GPIO[7 + 3 * 8]

#define FIO4DIR		GPIO[0 + 4 * 8]
#define FIO4MASK	GPIO[4 + 4 * 8]
#define FIO4PIN		GPIO[5 + 4 * 8]
#define FIO4SET		GPIO[6 + 4 * 8]
#define FIO4CLR		GPIO[7 + 4 * 8]
/* Note that this nomenclature works because of how
 * GPIO was first declared */

/* PINMODE RELATIVE MACROS */
#define PULLUP				0
#define REPEATER			1
#define NONE				2
#define PULLDOWN			3

/* FIODIR RELATIVE MACROS */
#define OUTPUT	1
#define INPUT	0

/* FIOPIN RELATIVE MACROS */
#define HIGH	1
#define LOW		0

/* FIOSET AND FIOCLR COMMON RELATIVE MACROS */
#define TRUE		1
#define UNCHANGED	0

void SetDIR (uint8_t port, uint8_t pin, uint8_t dir);
void SetMODE (uint8_t port, uint8_t pin, uint8_t mode);
void SetPIN (uint8_t port, uint8_t bit, uint8_t state);
void SetPIN_ALT (uint8_t port, uint8_t pin, uint8_t state);
uint8_t GetPIN (uint8_t port, uint8_t pin);

#endif /* DR_DR_GPIO_H_ */
