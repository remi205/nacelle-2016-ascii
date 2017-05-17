
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
