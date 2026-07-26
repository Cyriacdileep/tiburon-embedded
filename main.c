#include "uart.h"

int main(void)
{
    /* Initialize UART2 */
    UART2_Init();

    /* Send startup message */
    UART2_WriteString("UART Initialized\r\n");

    while (1)
    {
        /* Read one character */
        char c = UART2_ReadChar();

        /* Echo it back */
        UART2_WriteChar(c);
    }
}