#include "stm32f3xx_hal.h"
#include "gondola.h"
#include "ParameterParser.h"
#include "Serial.h"
#include <string.h>
#include <stdio.h>
#include "gpio_access.h"


////////////////////////////////////////////////////////////////////////
//  Function : Analyse
//  IN   :
//        
//  OUT  :
//  RET  :
//
//  Notes : analyse des commandes et traitement
//
/////////////////////////////////////////////////////////////////////////
int ServiceStm32_Analyse(char* Input)
{
  int status;
  ParameterParser m_Parser;
  m_Parser.ParseString(Input);

  char  resp[80];

  // m_Parser contient les parametres du profile à appliquer
  char * input_buf =  m_Parser.GetString(0);
  bool SendResponse = true;
  bool Ack = false;
  float val;

  if ( ! strcmp(input_buf, "gondola-led1")) {
    /* Alimente en PWM avec un duty cycle de 0 à 100% les Leds 1 qui balisent le trou d'entrée de la lumière. */
    int ratio;
    ratio = m_Parser.GetInteger(1);
    
    status = gondola_led1(ratio);
    
    Ack = true;
  } else if ( ! strcmp(input_buf, "gondola-led2")) {
    /* Alimente en PWM avec un duty cycle de 0 à 100% la Led 2 qui sert de reglage du renvoi coudé. */
    int ratio;
    ratio = m_Parser.GetInteger(1);
    
    status = gondola_led2(ratio);
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-led3", 12)) {
    /* Alimente en PWM avec un duty cycle de 0 à 100% la Led 3. */
    int ratio;
    ratio = m_Parser.GetInteger(1);
               
    status = gondola_led3(ratio);
               
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-bananapi-on", 19)) {
    /* Allume la carte banana pi. */
    
    status = gondola_bananapi_on();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-bananapi-off", 20)) {
    /* Eteint la carte banana pi. */
    
    status = gondola_bananapi_off();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-frangeur-on", 19)) {
    /* Allume le frangeur. */
    
    status = gondola_frangeur_on();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-frangeur-off", 20)) {
    /* Eteint le frangeur. */
    status = gondola_frangeur_off();
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-receiver-rc-on", 22)) {
    /* Allume l'alimentation du recepteur de Radio commande. */
    
    status = gondola_receiver_rc_on();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-receiver-rc-off", 23)) {
    /* Eteint l'alimentation du recepteur de Radio commande. */
    
    status = gondola_receiver_rc_off();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-cameras-on", 18)) {
    /* Alimente les caméra 'Champs','Pupille'. */
    
    status = gondola_camera_on();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-cameras-off", 19)) {
    /* Eteint les caméra 'Champs','Pupille'. */
    
    status = gondola_camera_off();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-wifi-antenna-on", 23)) {
    /* Allume l'antenne active Wifi. */
    
    status = gondola_wifi_antenna_on();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-wifi-antenna-off", 24)) {
    /* Eteint l'antenne active Wifi. */
    
    status = gondola_wifi_antenna_off();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-let-off-steam-on", 24)) {
    /* Allume le systeme antibuée. WM lent */
    int ratio;
    ratio = m_Parser.GetInteger(1);
    
    status = gondola_let_off_steam_on(ratio);
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-let-off-steam-off", 25)) {
    /* Eteint le systeme antibuée. */
    
    status = gondola_let_off_steam_off();
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-west-gauge", 18)) {
    /* Retourne la valeur de la mesure. */
    
    val = gondola_west_gauge();
    sprintf(resp, "U1 %f\n", val); 
    WriteConsole(resp);    
    SendResponse = false;
    Ack = true;

  } else if ( ! strncmp(input_buf, "gondola-east-low-gauge", 22)) {
    /* Retourne la valeur de la mesure. */
    
    val = gondola_east_low_gauge();
    sprintf(resp, "U1 %f\n", val);     
    WriteConsole(resp);    
    SendResponse = false;    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-east-high-gauge", 23)) {
    /* Retourne la valeur de la mesure. */
    
    val = gondola_east_high_gauge();
    sprintf(resp, "U1 %f\n", val);
    WriteConsole(resp);    
    SendResponse = false;
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-voltage-battery-low", 27)) {
    /* Retourne la valeur de la mesure. */
    
    val = gondola_voltage_battery_low();
    sprintf(resp, "U1 %f\n", val); 
    WriteConsole(resp);    
    SendResponse = false;
    
    Ack = true;
  } else if ( ! strncmp(input_buf, "gondola-voltage-battery-high", 28)) {
    /* Retourne la valeur de la mesure. */
    
    val = gondola_voltage_battery_high();
    sprintf(resp, "U1 %f\n", val); 
    WriteConsole(resp);    
    SendResponse = false;    
    Ack = true;
  } else if  ( ! strncmp(input_buf, "gondola-frangeur-camera-on", 26)) {
      status = gondola_frangeur_camera_on();
      Ack = true;
    
  } else if  ( ! strncmp(input_buf, "gondola-frangeur-camera-off", 27)) {
      status = gondola_frangeur_camera_off();
      Ack = true;

  } else if  ( ! strncmp(input_buf, "gondola-frangeur-motor-on", 25)) {
      status = gondola_frangeur_motor_on();
      Ack = true;

  } else if  ( ! strncmp(input_buf, "gondola-frangeur-motor-off", 26)) {
      status = gondola_frangeur_motor_off();
      Ack = true;

  } else if  ( ! strncmp(input_buf, "gondola-lan-switch-on", 21)) {
      status = gondola_lan_switch_on();
      Ack = true;
  }
  else if  ( ! strncmp(input_buf, "gondola-lan-switch-off", 22)) {
      status = gondola_lan_switch_off();
      Ack = true;
  }
  else if  ( ! strncmp(input_buf, "gondola-laser-on", 16)) {
    status = gondola_laser_on();
    Ack = true;
  }
  else if  ( ! strncmp(input_buf, "gondola-laser-off", 17)) {
    status = gondola_laser_off();
    Ack = true;
  }
  else if  ( ! strncmp(input_buf, "gondola-pesons-power-on", 23)) {
    status = gondola_laser_on();
    Ack = true;
  }
  else if  ( ! strncmp(input_buf, "gondola-pesons-power-off", 24)) {
    status = gondola_laser_off();
    Ack = true;
  }

  if ( SendResponse && !Ack)
    WriteConsole ("U0\n");
  
  if ( SendResponse && Ack)
    WriteConsole("U1\n");
 
  return true;
}
