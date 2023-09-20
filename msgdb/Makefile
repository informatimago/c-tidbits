all: example_before example_after
	example_before
	example_after

example_before: example_before.c
	$(CC) -o $@ $^

example_after: example_after_msgid.c
	$(CC) -o $@ $^

example_after_msgid.c : example_after.c
	./substitute_messages -o $@ $^

msg.db: example_after.c
	./extract_messages -o $@ $^


