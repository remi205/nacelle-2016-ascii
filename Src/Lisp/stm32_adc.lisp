

;; nacelle 2016
(setf l '
      (
       ("west-gauge" 1 "adc1" 1.00)
       ("east-low-gauge" 2 "adc1" 1.00)
       ("east-low-gauge" 3 "adc1" 1.00)
       ("south-4-gauge" 1 "adc2" 1.00)
       ("south-5-gauge" 2 "adc2" 1.00)
       ("south-5-gauge" 3 "adc2" 1.00)
       ("battery-low_voltage"  4 "adc2" 1.000)
       ("battery-high_voltage" 3 "adc2" 1.000)
      ))



(defun gen-get-value( list &key (stream t))
  (format stream "float get_~a()~%" (nth 0 list))
  (format stream "{~%")

  (format stream "	ADC_ChannelConfTypeDef adc_conf;~%")
  (format stream "	adc_conf.Channel = ADC_CHANNEL_~d;~%" (nth 1 list))
  (format stream "	HAL_ADC_ConfigChannel( &h~a, &adc_conf);~%" (nth 2 list))
  (format stream "	return ~f * adc_get_value(&h~a);~%"  (nth 3 list) (nth 2 list))
  (format stream "}~%~%~%"))

(defun gen-get-value-h( list &key (stream t))
  (format stream "extern float get_~a();~%" (nth 0 list)))


;; a priori rien a voir avec adc.
(defun pulse-length (duty period)
  (1- (/ (* (1+ period) duty) 100)))

; (pwm-frequency 8000 99)
(defun pwm-frequency(tick period)
  (/ tick (1+ period)))

;; 
(defun period(f-in precaler)
  (1- (/ f-in precaler)))

(defun pulse (duty tick p base precaler)
  (pulse-length duty (period (pwm-frequency tick precaler)
