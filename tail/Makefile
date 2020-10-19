all:tail
	@echo 'tail of 10 lines:'
	@./tail      < tail.c | cat -n 
	@echo 'tail of  3 lines:'
	@./tail -n 3 < tail.c | cat -n

tail:tail.c
clean:
	-rm -rf tail tail.dSYM
