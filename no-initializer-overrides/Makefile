PGMS = no-initializer-overrides-gcc no-initializer-overrides-clang
SOURCES = main.c

ifeq ($(shell uname -s),Darwin)
BLOCKS = -fblocks -lSystem
else
BLOCKS = -fblocks -lBlocksRuntime
endif

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ======= $$pgm ; ./$$pgm ; echo status=$$? ; done
	@echo // =======
no-initializer-overrides-gcc: $(SOURCES)
	@# with gcc, -Wno-initializer-overrides is not needed to suppress the warning
	gcc -Wall -Werror -std=c99 -o $@ $^
	gcc -Wall -Werror -Wno-initializer-overrides -std=c99 -o $@ $^
no-initializer-overrides-clang: $(SOURCES)
	@# with clang, -Wno-initializer-overrides is needed to suppress the warning
	clang -Wall -Werror $(BLOCKS) -std=c99 -o $@ $^  || true
	clang -Wall -Werror -Wno-initializer-overrides $(BLOCKS) -std=c99 -o $@ $^ 

clean:
	-rm -f $(PGMS) $(SOURCES:.c=.s) $(SOURCES:.c=.o)

