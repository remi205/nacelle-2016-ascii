# nacelle-2016-ascii

This firmware is a part of HyperTelescope gondola
Take commands from a xbee lp868 to drive led (pwm mode), power on/off device (cam, network and other device).

(gondola-led1 (ratio) "Alimente en PWM avec un duty cycle de 0 à 100% les Leds 1 qui balisent le trou d'entrée de la lumière.")
(gondola-led2 (ratio) "Alimente en PWM avec un duty cycle de 0 à 100% la Led 2 qui sert de reglage du renvoi coudé.")
(gondola-led3 (ratio) "Alimente en PWM avec un duty cycle de 0 à 100% la Led 3.")
(gondola-switch-ethernet-on   () "Allume le switch ethernet.")
(gondola-switch-ethernet-off  ()  "Eteint le switch ethernet.")
(gondola-laser-on             ()  "Allume le laser.")
(gondola-laser-off            ()  "Eteint le laser.")
(gondola-frangeur-on          ()  "Allume le frangeur.")
(gondola-frangeur-off         ()  "Eteint le frangeur.")
(gondola-lan-switch-on        ()  "Allume l'alimentation du recepteur de Radio commande.")
(gondola-lan-switch-off       ()  "Eteint l'alimentation du recepteur de Radio commande.")
(gondola-science-camera-on    ()	"Alimente la caméra 'Science'.")
(gondola-science-camera-off   ()   "Eteint la caméra  'Science'.")
(gondola-wifi-antenna-on      ()     "Allume l'antenne active Wifi.")
(gondola-wifi-antenna-off     ()   "Eteint l'antenne active Wifi.")
(gondola-pesons-power-on      ()	"Allume le system de mesure des pesons.")
(gondola-pesons-power-off     ()	"Eteint le systeme antibuée.")

 (gondola-west-gauge 	        ()	"Retourne la valeur de la mesure.")           
 (gondola-east-low-gauge	    ()	"Retourne la valeur de la mesure.")
 (gondola-voltage-battery-low ()	"Retourne la valeur de la mesure.")
 (gondola-voltage-battery-high()	"Retourne la valeur de la mesure.")
 
 (gondola-frangeur-camera-on  () "Allume la camera du frangueur")
 (gondola-frangeur-camera-off () "Eteint la camera du frangueur")
 (gondola-frangeur-motor-on   () "Allume le moteur du frangueur")
 (gondola-frangeur-motor-off  () "Eteint le moteur du frangueur"))
