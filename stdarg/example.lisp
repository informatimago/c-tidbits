(defun vf (&rest args)
  (reduce (function +) args))

(defun f (&rest args)
  (apply (function vf) args))

(defun main (args)
  (format t "(f 1 2 3)=~A~%" (f 1 2 3))
  (format t "(apply (function f) args)=~A~%" (apply (function f) args))
  0)

(main '(1 2 3 4 5))

prints:

(f 1 2 3)=6
(apply (function f) args)=15

returns: 0
