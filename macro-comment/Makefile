PGMS=macro-comment.e
all:$(PGMS)

macro-comment.e:macro-comment.c
	$(CC) -E -o macro-comment.e macro-comment.c
	cat macro-comment.e

clean:
	- for p in $(PGMS) ; do rm -rf $$p $${p}.dSYM ; done
