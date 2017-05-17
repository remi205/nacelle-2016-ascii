#pragma once
int gondola_led1(int ratio);
int gondola_led2(int ratio);
int gondola_led3(int ratio);
int gondola_bananapi_on();
int gondola_bananapi_off();
int gondola_frangeur_on();
int gondola_frangeur_off();
int gondola_receiver_rc_on();
int gondola_receiver_rc_off();
int gondola_camera_on();
int gondola_camera_off();
int gondola_wifi_antenna_on();
int gondola_wifi_antenna_off();
int gondola_let_off_steam_on(int ratio);
int gondola_let_off_steam_off();

// Mai 2017
int gondola_frangeur_camera_on();
int gondola_frangeur_camera_off();
int gondola_frangeur_motor_on();
int gondola_frangeur_motor_off();


float gondola_west_gauge();
float gondola_south_4_gauge();
float gondola_south_5_gauge();
float gondola_south_6_gauge();
float gondola_east_low_gauge();
float gondola_east_high_gauge();
float gondola_voltage_battery_low();
float gondola_voltage_battery_high();
int gondola_get_status();
int gondola_help();

