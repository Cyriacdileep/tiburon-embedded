#ifndef UART_H
#define UART_H

#include <stdint.h>


/* Initializes USART2 */
void UART2_Init(void);

/* Transmit one character */
void UART2_WriteChar(char c);

/* Transmit a string */
void UART2_WriteString(const char *str);

/* Receive one character */
char UART2_ReadChar(void);

#endif