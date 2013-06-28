
(require 'popup)

;;(setq popup-tip-max-width 150)
;(defvar translate_region_text "" )


(defun translate-zh2en ()
  "manage function  to get region , and use the onlinetranslate program."
  (interactive )

 ;; (cua-set-mark)
  (if (/= (point) (mark))
        (progn 
	 ;; (message "int prog\npoint: %d, mark:%d" (point) (mark))
	  (if (> (point) (mark))
	      (exchange-point-and-mark))
	  (setq translate_region_text (buffer-substring (point) (mark)))))
   ;; (message "point: %d, mark:%d" (point) (mark)))
  (let* (
	(command 
	 (format "echo %s | ot -s en  -d zh" translate_region_text))
	(result 
	 (shell-command-to-string command )))
  ;;  (message "int prog\npoint: %d, mark:%d" (point) (mark))
    (popup-tip result  :height 100 :margin 1 )))


(global-set-key [(f1)] 'translate-zh2en)







(provide 'onlinetranslate)










