PGMS = timeout-child-gcc timeout-child-clang \

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ====== $$pgm ; ./$$pgm ; done
	@echo // =======

timeout-child-gcc: main.c timeout.c 
	gcc   -Wall -std=c99 -DTIMEOUTLIB_H='"timeout.h"' -o $@ main.c timeout.c 
timeout-child-clang: main.c timeout.c 
	clang -Wall -std=c99 -DTIMEOUTLIB_H='"timeout.h"' -o $@ main.c timeout.c 

clean:
	-rm -f $(PGMS) *.o

