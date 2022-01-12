PGMS=atoi-test
all:$(PGMS)
clean:
	- for p in $(PGMS) ; do rm -rf $$p $${p}.dSYM ; done
test:atoi-test
	./atoi-test 42 0b101010 0x2a 052
