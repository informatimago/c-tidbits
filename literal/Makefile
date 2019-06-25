
all:benchmark

benchmark:
	make literal.c literal.s
	export CC=/opt/local/bin/gcc ; $$CC --version ; make clean-o literal.c.o literal.s.o
	export CC=/usr/bin/gcc       ; $$CC --version ; make clean-o literal.c.o literal.s.o

clean:clean-o
	rm -f literal.c literal.s
clean-o:
	rm -f literal.c.o literal.s.o

literal.s:generate-literal-s.lisp
	ccl -n -l $< -e '(ccl:quit)' > $@

literal.c:generate-literal-c.lisp
	ccl -n -l $< -e '(ccl:quit)' > $@

literal.c.o:literal.c
	time $(CC) -c -o $@ $<

literal.s.o:literal.s
	time $(CC) -c -o $@ $<
