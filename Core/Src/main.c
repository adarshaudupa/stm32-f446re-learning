#include "stm32f4xx.h"
#include "uart.h"

int main(void) {
    // Initialize UART
    UART2_Init(9600);

    // Send startup message
    UART2_SendString("UART RX/TX Echo Test\r\n");
    UART2_SendString("Type characters - they will echo back\r\n");
    UART2_SendString("Ready...\r\n\r\n");

    // Main loop: BLOCKING echo
    while (1) {
        // Wait for character (BLOCKING - CPU stuck here until byte arrives)
        char received = UART2_ReadChar();

        // Echo it back
        UART2_SendChar(received);

        // If Enter pressed, send newline
        if (received == '\r') {
            UART2_SendChar('\n');
        }
    }
}
