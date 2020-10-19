PGMS=test_1 test_n

all:$(PGMS)
	time ./test_n
	time ./test_1

clean:
	- for p in $(PGMS) ; do rm -rf $$p $${p}.dSYM ; done
	- rm -rf *.o remove_bits_1.c

test.o:test.c remove_bits.h print_binary.h
generate.o:generate.c remove_bits.h print_binary.h
remove_bits_n.o:remove_bits_n.c remove_bits.h
remove_bits_1.o:remove_bits_1.c remove_bits.h

remove_bits_1.c:generate
	./generate > remove_bits_1.c

generate:generate.o remove_bits_n.o print_binary.o
	$(CC) $(LDFLAGS)      -o $@ $^

test_n:test.o remove_bits_n.o print_binary.o
	$(CC) $(LDFLAGS)      -o $@ $^

test_1:test.o remove_bits_1.o print_binary.o
	$(CC) $(LDFLAGS)      -o $@ $^


