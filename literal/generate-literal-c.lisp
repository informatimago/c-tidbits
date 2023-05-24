(write-string "
#include \"literal.h\"
int int_sin_table[]={
")
(loop
  :for n :from 0
  :for phi :from 0.0d0 :to (/ pi 2) :by 0.000001d0
  :for s := (round (* #.(expt 2 30) (sin phi)))
  :do (format t "~:[~;~%~]~12D," (zerop (mod n 32)) s)
  :finally (format t "};~%int int_sin_table_count=~A;~%" n))
(finish-output)

