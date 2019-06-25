SAFE_LDFLAGS=\
	-fsanitize=leak

SAFE_CFLAGS=\
    -fsanitize=address \
    -fsanitize=null \
    -fsanitize=bounds \
    -fsanitize=vla-bound \
    -fsanitize=object-size \
    -fsanitize=unreachable \
    -fsanitize=shift \
    -fsanitize=shift-exponent \
    -fsanitize=shift-base \
    -fsanitize=integer-divide-by-zero \
    -fsanitize=signed-integer-overflow \
    -fsanitize=float-divide-by-zero \
    -fsanitize=float-cast-overflow \
    -fsanitize=nonnull-attribute \
    -fsanitize=returns-nonnull-attribute \
    -fsanitize=bool \
    -fsanitize=enum \
    -fsanitize-address-use-after-scope \
    -fsanitize-undefined-trap-on-error \
    -fstack-protector-all \
    -fstack-check

UNCOLOR = sed -e 's/\[[0-9;]*[a-z]//g'
all: safe unsafe
clean:
	- rm -f safe unsafe
test:all
	./safe   'Small arg'             2>&1 | $(UNCOLOR) || echo "exited with status $$?"
	./safe   'Is is a big argument.' 2>&1 | $(UNCOLOR) || echo "exited with status $$?"
	./unsafe 'Small arg'                               || echo "exited with status $$?"
	./unsafe 'Is is a big argument.'                   || echo "exited with status $$?"

safe:safety.c
	gcc $(SAFE_CFLAGS) $(SAFE_LDFLAGS) -fno-diagnostics-color  -O0 -g3 -o $@ $<

unsafe:safety.c
	gcc -O3 -o $@ $<

