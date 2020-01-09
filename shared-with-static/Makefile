all: test-m test-m2

test-m:m
	file *
	nm b.so
	nm m
	./m

test-m2:m2
	file *
	nm b2.so
	nm m2
	./m2
	rm f.so
	./m2

f.a:f.o
	ar cr $@ $<

f.o:f.c

b.o:b.c

b.so: b.o f.a
	ld -dylib -o $@ b.o f.a

clean:
	-rm -rf *.o *.a *.so m m2

m.o:m.c
m:m.o b.so
	gcc -o m m.o b.so

b2.so:b.o
	ld -dylib -o f.so f.o
	ld -dylib -o $@ b.o f.so -lsystem

m2:m.o b2.so f.a
	gcc -o m2 m.o b2.so f.a
