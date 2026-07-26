#include "spi.h"

int main(void)
{
    SPI1_Init();

    SPI1_SendByte(0x55);

    while(1)
    {

    }
}