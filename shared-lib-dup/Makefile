PGMS=pgm
SO=dylib
# SO=so

all:$(PGMS)

pgm:main.o libxw.$(SO) libyw.$(SO)
	$(CC) -o $@ $^

libxw.$(SO):xw.o libx.a
libyw.$(SO):yw.o liby.a

lib%.a:%.o
	ar r $@ $^

lib%.$(SO):%.o
	$(CC) -shared -o $@ $^


clean:
	-rm -rf *.a *.o *.$(SO) *~ $(PGMS)
