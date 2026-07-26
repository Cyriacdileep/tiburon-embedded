#ifndef SPI_H
#define SPI_H

void SPI1_Init(void);
void SPI1_SendByte(uint8_t data);
uint8_t SPI1_ReceiveByte(void);

#endif