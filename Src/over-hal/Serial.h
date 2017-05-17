#include "stm32f3xx_hal.h"

#pragma once

typedef int (* COMMAND_FUNC )(char * command);

int InitConsole( UART_HandleTypeDef * SerialPort, COMMAND_FUNC fn);
int WriteConsole(char * buffer);

#if 0
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#include "stm32f3xx_it.h"
#include "cmsis_os.h"

#include "BasicTypes.h"
#include "RegisterMacros.h"
#include "stm32_Uart_sci3.h"

extern DMA_HandleTypeDef hdma_usart2_rx;
extern UART_HandleTypeDef huart2;

void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
  if ( READ_CHARACTER_MATCH_INTERRUPT(UART_2) != 0)
  {  
    DISABLE_CHARACTER_MATCH_INTERRUPT(UART_2); 
    HAL_UART_DMAStop(&huart2);
    HAL_UART_RxCpltCallback(&huart2);     
  }
  
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}
#endif 
