PGMS=tee
all:$(PGMS)
clean:
	- for p in $(PGMS) ; do rm -rf $$p $${p}.dSYM ; done

tee.out.c:tee.c
    # pre-pro tee.c and output to tee.out.c
	$(CC) -E tee.c |sed -e 's/#.*//' > tee.out.c
