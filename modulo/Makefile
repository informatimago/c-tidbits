all:modulo-c89 modulo-c99
	@echo C89 ; ./modulo-c89
	@echo C99 ; ./modulo-c99
#CC=gcc
modulo-c89:modulo.c
	$(CC) -std=c89 -o $@ $^
modulo-c99:modulo.c
	$(CC) -std=c99 -o $@ $^

