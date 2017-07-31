/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "usart.h"
#include "over-hal/Serial.h"
#include "over-hal/gondola.h"
#include "over-hal/pwm.h"    
#include "over-hal/gpio_access.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

/* USER CODE BEGIN Variables */
extern int ServiceStm32_Analyse( char* Input);
extern void adc_init();
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);
extern float get_battery_high_voltage();
extern float get_battery_low_voltage();

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */
extern int ServiceStm32_Analyse( char* Input);

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  InitConsole(&huart1, ServiceStm32_Analyse);

  adc_init();
  gpio_direction(POWER_ALL_CAMERA, OUTPUT);  
  gpio_direction(POWER_FRANGEUR, OUTPUT);
  gpio_direction(POWER_FUBUTA, OUTPUT);
  gpio_direction(POWER_ANTENNA, OUTPUT);
  gpio_direction(POWER_BANANA, OUTPUT);
  gpio_direction(POWER_STEAM, OUTPUT);

  gpio_direction(POWER_FRANGEUR_CAM, OUTPUT);
  gpio_direction(POWER_FRANGEUR_MOTOR, OUTPUT);

  gpio_direction(POWER_SWITCH, OUTPUT);
  gpio_direction(POWER_LASER, OUTPUT);
  gpio_direction(POWER_PESONS, OUTPUT);

  // Led in pwm mode
  TimerFrequency(&htim1, TIM_CHANNEL_4, 7999);
  TimerFrequency(&htim3, TIM_CHANNEL_2, 7999);
  TimerFrequency(&htim3, TIM_CHANNEL_3, 7999);
 
#if 0
  SetRatio(&htim1, TIM_CHANNEL_4, 0);
  SetRatio(&htim3, TIM_CHANNEL_2, 0);
  SetRatio(&htim3, TIM_CHANNEL_3, 0);

  StartPwm(&htim1, TIM_CHANNEL_4);
  StartPwm(&htim3, TIM_CHANNEL_2);
  StartPwm(&htim3, TIM_CHANNEL_3);
#endif
  gpio_direction(POWER_STEAM, OUTPUT);       
  /* USER CODE END Init */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
#if 0
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 512);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
#endif
}

#if 0
/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);

    float m, n;
    
    m = 1.0 * get_battery_high_voltage();
    n = 1.0 * get_battery_low_voltage();
    m += n;
 //   ServiceStm32_Analyse("gondola-voltage-battery-high");
  }
}
#endif
