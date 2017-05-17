


#include "../over-hal/gpio_access.h"

unsigned long PreSleepProcessing( unsigned long xModifiableIdleTime)
{
  (void) xModifiableIdleTime;
  /* Disable the peripheral clock during Low Power (Sleep) mode.*/
    
  __USART2_CLK_DISABLE();
  __HAL_RCC_I2C1_CLK_DISABLE();
  __HAL_RCC_GPIOB_CLK_DISABLE(); 
  __HAL_RCC_GPIOF_CLK_DISABLE(); 
  
  
  
  return 1;
}

unsigned long PostSleepProcessing( unsigned long ulExpectedIdleTime)
{
  
  __USART2_CLK_ENABLE();
  __HAL_RCC_I2C1_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE(); 
  __HAL_RCC_GPIOF_CLK_ENABLE();   
  return 1;
  
}
