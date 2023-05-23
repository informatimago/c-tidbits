PGMS = test-lambda-gcc test-lambda-clang
all:$(PGMS)
SOURCES = $(wildcard *.c)
test-lambda-gcc: $(SOURCES)
	gcc            -DHAS_LOCAL_FUNCTIONS -UHAS_BLOCKS -std=c99 -o $@ $^
test-lambda-clang: $(SOURCES)
	clang -fblocks -UHAS_LOCAL_FUNCTIONS -DHAS_BLOCKS -std=c99 -o $@ $^

clean:
	-rm -f $(PGMS)
