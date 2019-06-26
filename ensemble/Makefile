NAME     = ensemble
SOURCES  = main.c $(NAME).c util.c list.c $(NAME)_bison.c $(NAME)_flex.c
OBJECTS  = $(SOURCES:.c=.o)
INCLUDES = -I.
CFLAGS  ?= $(INCLUDES)

ifeq ($(uname),Darwin)
LIBTOOL_FLAGS    = -s
DY_LIBTOOL_FLAGS = -macosx_version_min 10.14
else
LIBTOOL_FLAGS    = -s
DY_LIBTOOL_FLAGS =
endif

all:$(NAME) lib$(NAME).so

ifeq ($(uname),Darwin)

lib$(NAME).a: $(OBJECTS)
	libtool -static $(LIBTOOL_FLAGS)  -o $@ $^

lib$(NAME).so:lib$(NAME).a
	libtool -dynamic $(DY_LIBTOOL_FLAGS) -lc -o $@ $^

else

lib$(NAME).a: $(OBJECTS)
	ar cr $@ $^
	ranlib $@

lib$(NAME).so:lib$(NAME).a
	s=$^ ; mkdir -p $${s}.exploded \
	&& cd $${s}.exploded \
	&& ar x ../$$s \
	&& $(CC) -dynamic -o ../$(^:.a=.so) *.o
	- s=$^ ; rm -rf $${s}.exploded

endif

$(NAME)_flex.c: $(NAME).flex
	flex -o $@ $<

$(NAME)_bison.c: $(NAME).bison
	bison -o $@ $<

$(NAME)_flex.o: $(NAME)_flex.c util.h
$(NAME)_bison.o: $(NAME)_bison.c $(NAME).h list.h util.h
util.o:util.c util.h
list.o:list.c list.h util.h
$(NAME).o:$(NAME).c $(NAME).h util.h
main.o:main.c $(NAME).h

$(NAME):$(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

clean:
	-rm -rf $(OBJECTS)
	-rm -rf $(NAME)_flex.c $(NAME)_bison.c
	-rm -rf $(NAME)
	-rm -rf lib$(NAME).{so,a,dylib}



test:$(NAME)
	@echo 'Empty set test:'
	echo '{}' | ./$(NAME)
	@echo 'Simple test:'
	echo '{1,2,3}' | ./$(NAME)
	@echo 'Space test:'
	echo '  {  1   ,  2   ,   3  }  ' | ./$(NAME)
	@echo 'Multi-line test:'
	(echo '{11111,';echo '22222,';echo '33333}') | ./$(NAME)
	@echo 'Signed test:'
	echo '{-1000000000,-2000000,-3000,-4,-0,0,+0,+4,+3000,+2000000,+1000000000}' | ./$(NAME)

depends:
	CFLAGS="$(INCLUDES) -MMD" make
