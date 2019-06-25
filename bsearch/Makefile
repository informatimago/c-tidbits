LIBS=-lgc

ifeq ($(shell uname),Darwin)

PATH              = /opt/local/bin:/usr/local/bin:/usr/bin:/bin
CFLAGS            = -I/opt/local/include  -I/usr/local/include $(sanitize) -g -g3 -ggdb -O0 -std=c11
CXXFLAGS          = -I/opt/local/include  -I/usr/local/include $(sanitize) -g -g3 -ggdb -O0
LDFLAGS           = -L/opt/local/lib -L/usr/local/lib -L/usr/lib -rdynamic $(LIBS)
LD_LIBRARY_PATH   = /opt/local/lib:/usr/local/lib:/usr/lib:/lib
DYLD_LIBRARY_PATH = $(LD_LIBRARY_PATH)
dyld              = DYLD_LIBRARY_PATH=$(DYLD_LIBRARY_PATH)

else

PATH              = /usr/local/gcc/bin:/usr/local/bin:/usr/bin:/bin
CFLAGS            = -I/usr/local/gcc/include  -I/usr/local/include $(sanitize) -g -g3 -ggdb -O0 -std=c11
CXXFLAGS          = -I/usr/local/gcc/include  -I/usr/local/include $(sanitize) -g -g3 -ggdb -O0
LDFLAGS           = -L/usr/local/gcc/lib64 -L/usr/local/gcc/lib -L/usr/local/lib -L/usr/lib -L/lib -rdynamic  $(LIBS)
LD_LIBRARY_PATH   = /usr/local/gcc/lib64:/usr/local/gcc/lib:/usr/local/lib:/usr/lib:/lib
DYLD_LIBRARY_PATH = $(LD_LIBRARY_PATH)
dyld              = DYLD_LIBRARY_PATH=$(DYLD_LIBRARY_PATH)

endif

sanitize          = -fsanitize=address \
                    -fsanitize=null \
                    -fsanitize=bounds \
                    -fsanitize=vla-bound \
                    -fsanitize=object-size \
                    -fsanitize=unreachable \
                    -fsanitize=return \
                    -fsanitize=float-divide-by-zero \
                    -fsanitize=float-cast-overflow \
                    -fsanitize=nonnull-attribute \
                    -fsanitize=returns-nonnull-attribute \
                    -fsanitize=bool \
                    -fsanitize=enum \
                    -fsanitize-address-use-after-scope \
                    -fsanitize-undefined-trap-on-error \
                    -fstack-check \
					$(sanitize_$(shell uname))
sanitize_Darwin   =
sanitize_Linux    = -fstack-protector-all

CC                = gcc


all:bsearch
run:bsearch
	./bsearch
clean:
	-@rm -rf bsearch bsearch.o bsearch.a bsearch.dSYM
bsearch:bsearch.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
