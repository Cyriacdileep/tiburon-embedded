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