#include "gondola.h"
#include "gpio_access.h"

#include "tim.h"
#include "pwm.h"
#include "adc_nacelle.h"

//PA11  PWM_LED_1 TIM1 CHANNEL4
//PB5   PWM_LED_2 TIM3 CHANNEL2
//PB4   PWM_LED_3 TIM3 CHANNEL1

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim1;

/* Alimente en PWM avec un duty cycle de 0 à 100% les Leds 1 qui balisent le trou d'entrée de la lumière. */
int gondola_led1(int ratio)
  {
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
    SetRatio(&htim1, TIM_CHANNEL_4, ratio);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    return 0;
  }

/* Alimente en PWM avec un duty cycle de 0 à 100% la Led 2 qui sert de reglage du renvoi coudé. */
int gondola_led2(int ratio)
  {
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
    SetRatio(&htim3, TIM_CHANNEL_2, ratio);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    return 0;
  }

/* Alimente en PWM avec un duty cycle de 0 à 100% la Led 3. */
int gondola_led3(int ratio)
  {
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
    SetRatio(&htim3, TIM_CHANNEL_1, ratio);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    return 0;
  }

/* Allume la carte banana pi. */
int gondola_bananapi_on()
  {
   gpio_set(POWER_BANANA);
   return 0;
  }

/* Eteint la carte banana pi. */
int gondola_bananapi_off()
  {
  gpio_reset(POWER_BANANA);
  return 0;
  }

/* Allume le frangeur. */
int gondola_frangeur_on()
  {
    gpio_set(POWER_FRANGEUR);
    return 0;
  }

/* Eteint le frangeur. */
int gondola_frangeur_off()
  {
    gpio_reset(POWER_FRANGEUR);
    return 0;
  }


/* Allume l'alimentation du recepteur de Radio commande. */
int gondola_receiver_rc_on()
  {
    gpio_set(POWER_FUBUTA);
    return 0;
  }

/* Eteint l'alimentation du recepteur de Radio commande. */
int gondola_receiver_rc_off()
  {
    gpio_reset(POWER_FUBUTA);
    return 0;
    
  }

/* Alimente les caméra 'Champs','Pupille' et 'Ciel'. */
int gondola_camera_on()
  {
    gpio_set(POWER_ALL_CAMERA);
    return 0;
  }

/* Eteint les caméra 'Champs','Pupille' et 'Ciel'. */
int gondola_camera_off()
  {
    gpio_reset(POWER_ALL_CAMERA);
        return 0;

  }

/* Allume l'antenne active Wifi. */
int gondola_wifi_antenna_on()
  {
    gpio_set(POWER_ANTENNA);
    return 0;
 }

/* Eteint l'antenne active Wifi. */
int gondola_wifi_antenna_off()
  {
    gpio_reset(POWER_ANTENNA);
    return 0;
  }

/* Allume le systeme antibuée. WM lent */
int gondola_let_off_steam_on(int ratio)
  {
    gpio_set(POWER_STEAM);
    return 0;
  }

/* Eteint le systeme antibuée. */
int gondola_let_off_steam_off()
  {
    gpio_reset(POWER_STEAM);
    return 0;
  }

/* Retourne la valeur de la mesure. */
float gondola_west_gauge()
  {
    return get_peson1();
  }

/* Retourne la valeur de la mesure. */
float gondola_south_4_gauge()
  {
    return get_peson4();
  }

/* Retourne la valeur de la mesure. */
float gondola_south_5_gauge()
  {
    return get_peson5();
  }

/* Retourne la valeur de la mesure. */
float gondola_south_6_gauge()
  {
    return get_peson6();
  }

/* Retourne la valeur de la mesure. */
float  gondola_east_low_gauge()
  {
     return get_peson2();
  }

/* Retourne la valeur de la mesure. */
float gondola_east_high_gauge()
  {
     return get_peson1();
  }

/* Retourne la valeur de la mesure. */
float gondola_voltage_battery_low()
  {
     return get_battery_low_voltage();
  }

/* Retourne la valeur de la mesure. */
float gondola_voltage_battery_high()
  {
     return get_battery_high_voltage();
  }

int gondola_frangeur_camera_on()
{
   gpio_set(POWER_FRANGEUR_CAM);
   return 0;
}

int gondola_frangeur_camera_off()
{
    gpio_reset(POWER_FRANGEUR_CAM);
    return 0;
}

int gondola_frangeur_motor_on()
{
   gpio_set(POWER_FRANGEUR_MOTOR);
   return 0;
}

int gondola_frangeur_motor_off()
{
    gpio_reset(POWER_FRANGEUR_MOTOR);
    return 0;    
}
