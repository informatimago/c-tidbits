STD=c11
PGMS = default_noreturn-gcc  default_noreturn-clang \
	noreturn-gcc  noreturn-clang default_noreturn.e \
	uu_noreturn-gcc uu_noreturn-clang
SOURCES_noreturn = noreturn.c
SOURCES_default_noreturn = default_noreturn.c
SOURCES_uu_noreturn = uu_noreturn.c

ifeq ($(shell uname -s),Darwin)
BLOCKS = -fblocks -lSystem
else
BLOCKS = -fblocks -lBlocksRuntime
endif

all:$(PGMS)
	nm default_noreturn-clang
	grep foo0 < default_noreturn.e

# run:$(PGMS)
# 	@for pgm in $(PGMS) ; do echo // ======= $$pgm ; ./$$pgm ; echo status=$$? ; done
# 	@echo // =======

noreturn-gcc: $(SOURCES_noreturn)
	gcc -Wall -Werror -std=$(STD) -o $@ $^

noreturn-clang: $(SOURCES_noreturn)
	clang -Wall -Werror -std=$(STD) -o $@ $^ 

uu_noreturn-gcc: $(SOURCES_uu_noreturn)
	gcc -Wall -Werror -std=$(STD) -o $@ $^

uu_noreturn-clang: $(SOURCES_uu_noreturn)
	clang -Wall -Werror -std=$(STD) -o $@ $^ 

default_noreturn-gcc: $(SOURCES_default_noreturn)
	gcc -Wall -Werror -std=$(STD) -o $@ $^

default_noreturn-clang: $(SOURCES_default_noreturn)
	clang -Wall -Werror -std=$(STD) -o $@ $^ 

clean:
	-rm -f $(PGMS) $(SOURCES_noreturn:.c=.s) $(SOURCES_noreturn:.c=.o)
	-rm -f $(PGMS) $(SOURCES_default_noreturn:.c=.s) $(SOURCES_default_noreturn:.c=.o)

default_noreturn.e:$(SOURCES_default_noreturn)
	clang -E -Wall -Werror -std=$(STD) -o $@ $^ 
