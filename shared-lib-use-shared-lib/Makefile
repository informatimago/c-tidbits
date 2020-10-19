PGMS=pgm
SO=dylib
# SO=so

all:$(PGMS)

pgm:main.o libxw.$(SO) libx.$(SO) 
	$(CC) -o $@ $^

libxw.$(SO):xw.o libx.$(SO)
	$(CC) -shared -o $@ $^

lib%.$(SO):%.o
	$(CC) -shared -o $@ $^


clean:
	-rm -rf *.a *.o *.$(SO) *~ $(PGMS)
