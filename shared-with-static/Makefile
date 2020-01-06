all: m
	file *
	nm b.so
	./m

f.a:f.o
	ar cr $@ $<

f.o:f.c

b.o:b.c

b.so: b.o f.a
	ld -dylib -o $@ b.o f.a

clean:
	-rm -rf *.o *.a *.so m

m.o:m.c
m:m.o b.so
	gcc -o m m.o b.so
