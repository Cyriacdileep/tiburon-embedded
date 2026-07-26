#include "spi.h"

/* Base addresses */
#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x50000000
#define SPI1_BASE   0x40013000

/* Register definitions */
#define RCC_IOPENR      (*(volatile unsigned int*)(RCC_BASE + 0x2C))
#define RCC_APBENR2     (*(volatile unsigned int*)(RCC_BASE + 0x3C))

#define GPIOA_MODER     (*(volatile unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL      (*(volatile unsigned int*)(GPIOA_BASE + 0x20))

#define SPI1_CR1        (*(volatile unsigned int*)(SPI1_BASE + 0x00))
#define SPI1_SR         (*(volatile unsigned int*)(SPI1_BASE + 0x08))
#define SPI1_DR         (*(volatile unsigned int*)(SPI1_BASE + 0x0C))

void SPI1_Init(void)
{
    /* Enable clocks */

    /* Configure GPIO pins for
       SCK
       MOSI
       MISO
    */

    /* Configure SPI
       Master mode
       Clock polarity
       Clock phase
       Baud rate
    */

    /* Enable SPI */
}

void SPI1_SendByte(uint8_t data)
{
    while(!(SPI1_SR & (1<<1)));   // TXE

    SPI1_DR = data;
}

uint8_t SPI1_ReceiveByte(void)
{
    while(!(SPI1_SR & (1<<0)));   // RXNE

    return SPI1_DR;
}