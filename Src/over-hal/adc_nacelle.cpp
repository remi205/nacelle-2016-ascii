#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include "adc.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

volatile unsigned long data_ready;

osSemaphoreId SemaphoreIncommingValue;
osSemaphoreDef(SemaphoreIncommingValue);

#define LENGTH 10

void adc_init()
{
    // le semaphore rx 
  SemaphoreIncommingValue = osSemaphoreCreate(osSemaphore(SemaphoreIncommingValue), 1);  
}

unsigned long adc_get_value(ADC_HandleTypeDef *adc)
{
  unsigned long data = 0;
 
  for ( int i = 0 ; i < LENGTH; i++)
    {
      if ( HAL_ADC_Start_IT(adc) == HAL_OK )
        {
          // on attend une trame pendent 20 ms
          osSemaphoreWait(SemaphoreIncommingValue, 20);
          data += HAL_ADC_GetValue(adc);
          HAL_ADC_Stop_IT(adc);
        }
    }
  return data/ (float) LENGTH;
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	osSemaphoreRelease(SemaphoreIncommingValue);
}

float get_peson1()
{
	ADC_ChannelConfTypeDef adc_conf;
	adc_conf.Channel = ADC_CHANNEL_1;
    adc_conf.Rank = 1;
    adc_conf.SingleDiff = ADC_SINGLE_ENDED;
    adc_conf.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    adc_conf.OffsetNumber = ADC_OFFSET_NONE;
    adc_conf.Offset = 0;
	HAL_ADC_ConfigChannel( &hadc1, &adc_conf);
	return 1.001 * adc_get_value(&hadc1);
}

float get_peson2()
{
	ADC_ChannelConfTypeDef adc_conf;
	adc_conf.Channel = ADC_CHANNEL_2;
    adc_conf.Rank = 1;
    adc_conf.SingleDiff = ADC_SINGLE_ENDED;
    adc_conf.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    adc_conf.OffsetNumber = ADC_OFFSET_NONE;
    adc_conf.Offset = 0;
	HAL_ADC_ConfigChannel( &hadc1, &adc_conf);
	return 0.99 * adc_get_value(&hadc1);
}

float get_battery_low_voltage()
{
	ADC_ChannelConfTypeDef adc_conf;
        
	adc_conf.Channel = ADC_CHANNEL_3;
    adc_conf.Rank = 1;
    adc_conf.SingleDiff = ADC_SINGLE_ENDED;
    adc_conf.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    adc_conf.OffsetNumber = ADC_OFFSET_NONE;
    adc_conf.Offset = 0;

	HAL_ADC_ConfigChannel( &hadc1, &adc_conf);
	return 0.0024912258 * adc_get_value(&hadc1);
}


float get_battery_high_voltage()
{
	ADC_ChannelConfTypeDef adc_conf;
        
	adc_conf.Channel = ADC_CHANNEL_4;    
        adc_conf.Rank = 1;
        adc_conf.SingleDiff = ADC_SINGLE_ENDED;
        adc_conf.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
        adc_conf.OffsetNumber = ADC_OFFSET_NONE;
        adc_conf.Offset = 0;        
	HAL_ADC_ConfigChannel( &hadc2, &adc_conf);
	return 0.0042625005 * adc_get_value(&hadc2);
}

float get_test_adc()
{
	ADC_ChannelConfTypeDef adc_conf;
	adc_conf.Channel = ADC_CHANNEL_4;
        
        adc_conf.Rank = 1;
        adc_conf.SingleDiff = ADC_SINGLE_ENDED;
        adc_conf.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
        adc_conf.OffsetNumber = ADC_OFFSET_NONE;
        adc_conf.Offset = 0;  
        
	HAL_ADC_ConfigChannel(&hadc2, &adc_conf);
	return 1.0 * adc_get_value(&hadc1);
}


