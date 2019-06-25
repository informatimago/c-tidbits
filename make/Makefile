SHELL=$(PWD)/do
.SHELLFLAGS=
all:do
do:do.o
	@ link do.o into do
do.o:do.c
	@ compile do.c into do.o
clean::
	@ delete object files 
