PGMS = no-initializer-overrides-gcc no-initializer-overrides-clang
SOURCES = main.c

ifeq ($(shell uname -s),Darwin)
BLOCKS = -fblocks -lSystem
else
BLOCKS = -fblocks -lBlocksRuntime
endif

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ====== $$pgm ; ./$$pgm ; done
	@echo // =======
no-initializer-overrides-gcc: $(SOURCES)
	gcc -Wall -Wno-initializer-overrides -std=c99 -o $@ $^
no-initializer-overrides-clang: $(SOURCES)
	clang -Wall -Wno-initializer-overrides $(BLOCKS) -std=c99 -o $@ $^ 

clean:
	-rm -f $(PGMS) $(SOURCES:.c=.s) $(SOURCES:.c=.o)

