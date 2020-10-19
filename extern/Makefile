all: test-extern
test-extern:main.o lib.a
	$(CC) -o $@ main.o lib.a
main.o:main.c lib.h
lib.o:lib.c lib.h
lib.a:lib.o
	ar cr $@ $<

clean:
	- rm -rf *.o *.a test-extern test-extern.dSYM
