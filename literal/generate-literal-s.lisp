(write-string "
	.section	__DATA,__data
	.globl	_int_sin_table
	.globl	_int_sin_table_count
	.p2align	2

_int_sin_table:
")
(loop
  :for n :from 0
  :for phi :from 0.0d0 :to (/ pi 2) :by 0.000001d0
  :for s := (round (* #.(expt 2 30) (sin phi)))
  :do (format t "    .long    ~A~%" s)
  :finally (format t "_int_sin_table_count:~%    .long    ~A~%" n))
(write-string "
.subsections_via_symbols
")
