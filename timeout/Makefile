PGMS = timeout-pthread-gcc timeout-pthread-clang \
       timeout-sigalrm-gcc timeout-sigalrm-clang

ifeq ($(shell uname -s),Darwin)
BLOCKS = -fblocks -lSystem
else
BLOCKS = -fblocks -lBlocksRuntime
endif

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ====== $$pgm ; ./$$pgm ; echo // ------ ; ./$$pgm --block ; done
	@echo // =======

timeout-pthread-gcc: main.c timeout-pthread.c 
	gcc             -Wall -std=c99 -DTIMEOUTLIB_H='"timeout-pthread.h"' -o $@ main.c timeout-pthread.c 
timeout-pthread-clang: main.c timeout-pthread.c 
	clang $(BLOCKS) -Wall -std=c99 -DTIMEOUTLIB_H='"timeout-pthread.h"' -o $@ main.c timeout-pthread.c 

timeout-sigalrm-gcc: main.c timeout-sigalrm.c 
	gcc             -Wall -std=c99 -DTIMEOUTLIB_H='"timeout-sigalrm.h"' -o $@ main.c timeout-sigalrm.c 
timeout-sigalrm-clang: main.c timeout-sigalrm.c 
	clang $(BLOCKS) -Wall -std=c99 -DTIMEOUTLIB_H='"timeout-sigalrm.h"' -o $@ main.c timeout-sigalrm.c 

clean:
	-rm -f $(PGMS) *.o

