/*
 * DR_UART.h
 *
 *  Created on: 10 Oct 2019
 *      Author: rnsavinelli
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "DR_Variables.h"

#define		UART0		0
#define		UART1		1
// #define		UART2		2
// #define		UART3		3

/* Pins to interact with the UART's */
#define		TXD0		0, 2
#define		RXD0		0, 3
#define		TXD1		0, 15
#define		RXD1		0, 16

#define		PCONP		( ( __RW uint32_t * ) 0x400FC0C4UL )

/* UART0 uses PCONP[3]  */
/* UART1 uses PCONP[4]  */
/* UART2 uses PCONP[24] */
/* UART3 uses PCONP[25] */

/* BIT CONFIGURATION on the manual (UM10360.pdf) page 59 */

/* HAS UATR 0 AND 1 REGISTERS */
#define		PCLKSEL0	(* ( ( __RW uint32_t * ) 0x400FC1A8UL ) )

/* HAS UART 2 AND 3 REGISTERS */
// #define		PCLKSEL1	(* ( ( __RW uint32_t * ) 0x400FC1ACUL ) )

/* Receiver Buffer Registers (WHEN DLAB == 0) */
#define		U0RBR		(* ( __R uint32_t * ) 0x4000C000UL )
#define		U1RBR		(* ( __R uint32_t * ) 0x40010000UL )
// #define		U2RBR		(* ( __R uint32_t * ) 0x40098000UL )
// #define		U3RBR		(* ( __R uint32_t * ) 0x4009C000UL )

/* Transmitter Holding Registers (WHEN DLAB == 0) */
#define		U0THR		(* ( __W uint32_t * ) 0x4000C000UL )
#define		U1THR		(* ( __W uint32_t * ) 0x40010000UL )
// #define		U2THR		(* ( __W uint32_t * ) 0x40098000UL )
// #define		U3THR		(* ( __W uint32_t * ) 0x4009C000UL )

/* Divisor Latch LSB Registers */
#define		U0DLL		(* ( __RW uint32_t * ) 0x4000C000UL )
#define		U1DLL		(* ( __RW uint32_t * ) 0x40010000UL )
// #define		U2DLL		(* ( __RW uint32_t * ) 0x40098000UL )
// #define		U3DLL		(* ( __RW uint32_t * ) 0x4009C000UL )

/* Divisor Latch MSB Registers */
#define		U0DLM		(* ( __RW uint32_t * ) 0x4000C004UL )
#define		U1DLM		(* ( __RW uint32_t * ) 0x40010004UL )
// #define		U2DLM		(* ( __RW uint32_t * ) 0x40098004UL )
// #define		U3DLM		(* ( __RW uint32_t * ) 0x4009C004UL )

/* Interrupt Enable Registers (WHEN DLAB == 0) */
#define		U0IER		(* ( __RW uint32_t * ) 0x4000C004UL )
#define		U1IER		(* ( __RW uint32_t * ) 0x40010004UL )
// #define		U2IER		(* ( __RW uint32_t * ) 0x40098004UL )
// #define		U3IER		(* ( __RW uint32_t * ) 0x4009C004UL )

/* Interrupt ID Registers */
#define		U0IIR		(* ( __R uint32_t * ) 0x4000C008UL )
#define		U1IIR		(* ( __R uint32_t * ) 0x40010008UL )
// #define		U2IIR		(* ( __R uint32_t * ) 0x40098008UL )
// #define		U3IIR		(* ( __R uint32_t * ) 0x4009C008UL )

/* FIFO Control Registers */
#define		U0FCR		(* ( __W uint32_t * ) 0x4000C008UL )
#define		U1FCR		(* ( __W uint32_t * ) 0x40010008UL )
// #define		U2FCR		(* ( __W uint32_t * ) 0x40098008UL )
// #define		U3FCR		(* ( __W uint32_t * ) 0x4009C00CUL )

/* UARTn Line Control Registers */
#define		U0LCR		(* ( __RW uint32_t * ) 0x4000C00CUL )
#define		U1LCR		(* ( __RW uint32_t * ) 0x4001000CUL )
// #define		U2LCR		(* ( __RW uint32_t * ) 0x4009800CUL )
// #define		U3LCR		(* ( __RW uint32_t * ) 0x4009C00CUL )

/* Line Status Register */
#define		U0LSR		(* ( __R uint32_t * ) 0x4000C014UL )
#define		U1LSR		(* ( __R uint32_t * ) 0x40010014UL )
// #define		U2LSR		(* ( __R uint32_t * ) 0x40098014UL )
// #define		U3LSR		(* ( __R uint32_t * ) 0x4009C014UL )

#define		TX0_BUFFER_SIZE		512
#define		TX1_BUFFER_SIZE		512
#define		RX0_BUFFER_SIZE		512
#define		RX1_BUFFER_SIZE		512

#define		UART0_BAUDRATE		9600
#define		UART1_BAUDRATE		9600

extern uint8_t g_inTx0, g_outTx0;
extern uint8_t g_bufferTx0[TX0_BUFFER_SIZE];

extern uint8_t g_inTx1, g_outTx1;
extern uint8_t g_bufferTx1[TX1_BUFFER_SIZE];

void UARTn_Initialize(uint8_t uart_number);

void UARTn_PushTx(uint8_t uart_number, uint8_t data_byte);
int16_t UARTn_PopTx(uint8_t uart_number);

void UARTn_PushRx(uint8_t uart_number, uint8_t data_byte);
int16_t UARTn_PopRx(uint8_t uart_number);

#endif /* DR_UART_H_ */
