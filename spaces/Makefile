PGM=the\ program
all: $(PGM)
$(PGM): the\ main\ function.o foo\ bar.o ; gcc -o $(PGM) the\ main\ function.o foo\ bar.o -lc
the\ main\ function.o : the\ main\ function.c foo\ bar.h ; gcc -c -o the\ main\ function.o the\ main\ function.c
foo\ bar.o : foo\ bar.c foo\ bar.h ; gcc -c -o foo\ bar.o foo\ bar.c -lc
clean:
	-rm -f *.o $(PGM)
