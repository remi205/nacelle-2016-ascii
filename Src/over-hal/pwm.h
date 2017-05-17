
#pragma once

void StartPwm(TIM_HandleTypeDef *Timer, unsigned char Channel);
void TimerFrequency( TIM_HandleTypeDef *Timer, unsigned char Channel, unsigned int value);
void SetRatio(TIM_HandleTypeDef *Timer, unsigned char Channel, int PerCent);

