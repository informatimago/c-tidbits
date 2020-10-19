all:cbomb
cbomb:
	@echo "This program makes the C compiler use a lot of time (and possibly eventually "
	@echo "crash.  So please, don't try to compile it."
	@echo "If you really must, use the force-cbomb target."
force-cbomb:cbomb.c
	-time cc    -mcmodel=medium -Wno-main -Wno-implicit-int cbomb.c -o cbomb
	-time clang -mcmodel=medium -Wno-main -Wno-implicit-int cbomb.c -o cbomb
	-time gcc   -mcmodel=medium -Wno-main -Wno-implicit-int cbomb.c -o cbomb
clean:
	- rm -rf *~
