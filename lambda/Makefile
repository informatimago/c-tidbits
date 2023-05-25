PGMS = test-lambda-gcc test-lambda-clang
SOURCES = clang-block.c gcc-local-function.c lambda.c main.c

ifeq ($(shell uname -s),Darwin)
BLOCKS = -fblocks -lSystem
else
BLOCKS = -fblocks -lBlocksRuntime
endif

all:run
run:$(PGMS)
	@for pgm in $(PGMS) ; do echo // ====== $$pgm ; ./$$pgm ; done
	@echo // =======
test-lambda-gcc: $(SOURCES)
	gcc -Wall -std=c99 -o $@ $^
test-lambda-clang: $(SOURCES)
	clang -Wall $(BLOCKS) -std=c99 -o $@ $^ 

clean:
	-rm -f $(PGMS) $(SOURCES:.c=.s) $(SOURCES:.c=.o)

assembly:$(SOURCES:.c=.s)
objects:$(SOURCES:.c=.o)

$(SOURCES:.c=.s):$(SOURCES)
	/build/pbourguignon/src.devel/vlm-clang-prebuilts-android/clang-r450784d/bin/clang \
		-target aarch64-linux-android \
		-mcpu=cortex-a53 \
		--sysroot=/home/pbourguignon/src/android/prebuilt/r25-sysroot \
		-Wno-int-to-pointer-cast \
		-Wno-pointer-to-int-cast \
		-Wno-implicit-function-declaration \
		-g \
		-fprofile-instr-generate \
		-fcoverage-mapping \
		$(BLOCKS) -std=c99 -S $^


$(SOURCES:.c=.o):$(SOURCES)
	/build/pbourguignon/src.devel/vlm-clang-prebuilts-android/clang-r450784d/bin/clang \
		-target aarch64-linux-android \
		-mcpu=cortex-a53 \
		--sysroot=/home/pbourguignon/src/android/prebuilt/r25-sysroot \
		-Wno-int-to-pointer-cast \
		-Wno-pointer-to-int-cast \
		-Wno-implicit-function-declaration \
		-g \
		-fprofile-instr-generate \
		-fcoverage-mapping \
		$(BLOCKS) -std=c99 -c $^
