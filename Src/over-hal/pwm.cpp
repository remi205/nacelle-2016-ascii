#include "stm32f3xx_hal.h"

#include "tim.h"
#include "pwm.h"

char InitLed( TIM_HandleTypeDef *Timer, unsigned char Channel, unsigned Precaler)
{
  return 0;
}

// TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3, TIM_CHANNEL_4
void StartPwm(TIM_HandleTypeDef *Timer, unsigned char Channel)
{
  HAL_TIM_PWM_Start(Timer, Channel);
}

// Ratio 50%, Attention cela dépend de l'horloge du timer
void TimerFrequency( TIM_HandleTypeDef *Timer, unsigned char Channel, unsigned int value)
{
  Timer->Init.Prescaler = value;
  Timer->Init.Period = 99;
  HAL_TIM_Base_Init(Timer);
}

void SetRatio(TIM_HandleTypeDef *Timer, unsigned char Channel, int PerCent)
{
  TIM_OC_InitTypeDef sConfigOC;
  
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = PerCent;
  HAL_TIM_PWM_ConfigChannel(Timer, &sConfigOC, Channel);
}


