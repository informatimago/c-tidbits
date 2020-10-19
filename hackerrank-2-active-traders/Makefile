CFLAGS=-g3 -ggdb

all:active-traders input-1.txt input-2.txt input-3.txt
	OUTPUT_PATH=output-1.txt ./active-traders < input-1.txt && cat output-1.txt
	OUTPUT_PATH=output-2.txt ./active-traders < input-2.txt && cat output-2.txt
	OUTPUT_PATH=output-3.txt ./active-traders < input-3.txt && cat output-3.txt

input-3.txt:Makefile
	(echo 100000 ;\
	 i=0;while [ $$i -lt 20000 ] ; do echo "Grossium" ; i=$$(( i + 1)) ; done ;\
	 head -n 80000 /usr/share/dict/words ) > $@

clean:
	-rm -rf active-traders *.dSYM output-*.txt input-3.txt
