/*
 * PR_UART.h
 *
 *  Created on: 17 Oct 2019
 *      Author: rnsavinelli
 */

#ifndef PR_UART_H_
#define PR_UART_H_

#include "DR_Variables.h"

uint8_t SendData(uint8_t uart, const uint8_t * data, uint8_t data_length);

#endif /* PR_UART_H_ */
