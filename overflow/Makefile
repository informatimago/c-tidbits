PGMS=overflow
all:$(PGMS)
run:$(PGMS)
	-./overflow ; echo status = $$?
clean:
	- for p in $(PGMS) ; do rm -rf $$p $${p}.dSYM ; done
