LINE=------------------------------------------------------------------------

all::$(PGMS)

.PHONY::all clean run test

clean::
	- for pgm in $(PGMS) ; do rm -rf $${pgm} $${pgm}.dSYM ; done

run:: $(PGMS)
	@for pgm in $(PGMS) ; do echo "$(LINE)" ; ./$${pgm} ; done ; echo "$(LINE)" 

test:: run
