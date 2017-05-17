
#include <string.h>
#include "Console.h"
#include "usart.h"

extern UART_HandleTypeDef huart2;

int WriteConsole2(char * s)
{
  HAL_UART_Transmit(&huart2, (uint8_t*)s, strlen(s), 100);
  return 0;
}

