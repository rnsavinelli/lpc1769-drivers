/*
 * DR_ADC.h
 *
 *  Created on: 6 Nov 2019
 *      Author: rnsavinelli (R. Nicolás Savinelli)
 */

#ifndef DR_ADC_H_
#define DR_ADC_H_

#include "DR_Variables.h"

/* A/D Control Register */
#define		AD0CR	 (* ( uint32_t  * ) 0x40034000UL )
/* A/D Global Data Register */
#define		AD0GDR	 (* ( uint32_t  * ) 0x40034004UL )
/* A/D Interrupt Enable Register */
#define		AD0INTEN (* ( uint32_t  * ) 0x4003400CUL )
/* A/D Channel 0 Data Register */
#define		AD0DR0	 (* ( uint32_t  * ) 0x40034010UL )

/* D/A Converter Register */
#define		DACR	 (* ( uint32_t  * ) 0x4008C000UL )
/* DAC Control register */
#define		DACCTRL	 (* ( uint32_t  * ) 0x4008C004UL )
/* DAC Counter Value register */
#define		DACCNTVAL (* ( uint32_t  * ) 0x4008C008UL )

/* A/D Channel Data Registers */
#define	AD0DR1		AD0DR0[1]
#define	AD0DR2		AD0DR0[2]
#define	AD0DR3		AD0DR0[3]
#define	AD0DR4		AD0DR0[4]
#define	AD0DR5		AD0DR0[5]
#define	AD0DR6		AD0DR0[6]
#define	AD0DR7		AD0DR0[7]

#define	ADC0_VAL		ADC_VAL(AD0DR0)
#define	ADC1_VAL		ADC_VAL(AD0DR1)
#define	ADC2_VAL		ADC_VAL(AD0DR2)
#define	ADC3_VAL		ADC_VAL(AD0DR3)
#define	ADC4_VAL		ADC_VAL(AD0DR4)
#define	ADC5_VAL		ADC_VAL(AD0DR5)
#define	ADC6_VAL		ADC_VAL(AD0DR6)
#define	ADC7_VAL		ADC_VAL(AD0DR7)

/* DAC and ADC ports */
#define DAC0		0,26

#define	ADC0_0      0,23
#define	ADC0_1      0,24
#define	ADC0_2 	   	0,25
#define	ADC0_3      0,26
#define	ADC0_4      1,30
#define	ADC0_5      1,31
#define	ADC0_6      0,3
#define	ADC0_7      0,2

/* channels */
#define AD0_CH0 		0
#define AD0_CH1 		1
#define AD0_CH2 		2
#define AD0_CH3 		3
#define AD0_CH4 		4
#define AD0_CH5 		5
#define AD0_CH6 		6
#define AD0_CH7 		7

#define SAMPLE_LIMIT	128

extern volatile uint32_t ADC1_value[SAMPLE_LIMIT];
extern volatile uint32_t ADC2_value[SAMPLE_LIMIT];
extern volatile uint32_t ADC5_value[SAMPLE_LIMIT];

/* Functions */
void ADC_Initialize(void);
void DAC_Initialize(void);

#endif /* DR_ADC_H_ */
