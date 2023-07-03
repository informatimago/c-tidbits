PGMS      = print-sizes-gcc print-sizes-clang
SOURCES   = print-sizes.c

GCC_OPT   = 
CLANG_OPT = -fblocks -lBlocksRuntime

all: $(PGMS)
	./print-sizes-gcc
	./print-sizes-clang

print-sizes-gcc: $(SOURCES)
	gcc   -Wall -std=c99 $(GCC_OPT)   -o $@ $^
print-sizes-clang: $(SOURCES)
	clang -Wall -std=c99 $(CLANG_OPT) -o $@ $^ 

