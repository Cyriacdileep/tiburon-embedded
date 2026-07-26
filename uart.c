#include "uart.h"
#include <stdint.h>

/* ============================================================
 * UART Driver for STM32C031C6
 * Register-Level Implementation
 * ============================================================
 */

/* ---------------- RCC Registers ---------------- */

#define RCC_BASE        0x40021000UL

#define RCC_IOPENR      (*(volatile uint32_t *)(RCC_BASE + 0x34))
#define RCC_APBENR1     (*(volatile uint32_t *)(RCC_BASE + 0x3C))

/* ---------------- GPIOA Registers ---------------- */

#define GPIOA_BASE      0x50000000UL

#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL      (*(volatile uint32_t *)(GPIOA_BASE + 0x20))

/* ---------------- USART2 Registers ---------------- */

#define USART2_BASE     0x40004400UL

#define USART2_CR1      (*(volatile uint32_t *)(USART2_BASE + 0x00))
#define USART2_BRR      (*(volatile uint32_t *)(USART2_BASE + 0x0C))
#define USART2_ISR      (*(volatile uint32_t *)(USART2_BASE + 0x1C))
#define USART2_RDR      (*(volatile uint32_t *)(USART2_BASE + 0x24))
#define USART2_TDR      (*(volatile uint32_t *)(USART2_BASE + 0x28))

/* ---------------- Bit Definitions ---------------- */

#define GPIOAEN         (1U << 0)
#define USART2EN        (1U << 17)

#define UE              (1U << 0)
#define RE              (1U << 2)
#define TE              (1U << 3)

#define RXNE            (1U << 5)
#define TXE             (1U << 7)

void UART2_Init(void)
{
    /* Enable GPIOA clock */
    RCC_IOPENR |= GPIOAEN;

    /* Enable USART2 clock */
    RCC_APBENR1 |= USART2EN;

    /* Configure PA2 and PA3 as Alternate Function */
    GPIOA_MODER &= ~((3U << 4) | (3U << 6));
    GPIOA_MODER |=  ((2U << 4) | (2U << 6));

    /* Select AF1 for USART2 */
    GPIOA_AFRL &= ~((0xFU << 8) | (0xFU << 12));
    GPIOA_AFRL |=  ((1U << 8) | (1U << 12));

    /* 9600 baud @ 16 MHz */
    USART2_BRR = 1667;

    /* Enable Transmitter and Receiver */
    USART2_CR1 |= TE;
    USART2_CR1 |= RE;

    /* Enable USART2 */
    USART2_CR1 |= UE;
}
/*
 * Transmit a single character
 */
void UART2_WriteChar(char c)
{
    /* Wait until transmit data register is empty */
    while (!(USART2_ISR & TXE));

    /* Write character to transmit register */
    USART2_TDR = (uint8_t)c;
}