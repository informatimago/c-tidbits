PGMS = test-lambda-gcc test-lambda-clang
SOURCES = clang-block.c gcc-local-function.c lambda.c main.c

ifeq ($(shell uname -s),Darwin)
        BLOCKS = -fblocks -lSystem
else
	BLOCKS = -fblocks -lBlocksRuntime
endif

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ====== $$pgm ; ./$$pgm ; done
	@echo // =======
test-lambda-gcc: $(SOURCES)
	gcc -std=c99 -o $@ $^
test-lambda-clang: $(SOURCES)
	clang $(BLOCKS) -std=c99 -o $@ $^ 

clean:
	-rm -f $(PGMS)
