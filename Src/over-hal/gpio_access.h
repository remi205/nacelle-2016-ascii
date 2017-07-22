#include "stm32f3xx_hal.h"

#pragma once
//////////////////////////////////////////////////////////

#include "gpio_base.h"

// board GPIO

#define POWER_ALL_CAMERA  PA12
#define POWER_ANTENNA     PB0


#define POWER_FUBUTA      PF0
#define POWER_SWITCH      PF0


// #### 5V
#define POWER_BANANA      PA8
#define POWER_LASER       PA8

#define POWER_FRANGEUR    PB1

// #### 5V
#define POWER_STEAM       PF1
#define POWER_PESONS      PF1


#define POWER_FRANGEUR_MOTOR PA6 // gondola-frangeur-motor
#define POWER_FRANGEUR_CAM   PA5 // gondola-frangeur-camera

#define LD3               PB3

//////////////////////////////////////////////////////////
typedef enum io_direction {
  OUTPUT,
  INPUT
} io_direction;


typedef enum io_event_mode {
  MODE_INPUT,
  MODE_RISING,
  MODE_FALLING,
  MODE_RISING_FALLING
} io_event_mode;


//////////////////////////////////////////////////////////


void         gpio_set       ( unsigned int gpio_number);
void         gpio_reset     ( unsigned int gpio_number);
unsigned int gpio_get       ( unsigned int gpio_number);
unsigned int gpio_pulse     ( unsigned int gpio_number);
void         gpio_direction ( unsigned int gpio_number, enum io_direction dir);


