#include <stdio.h>
#include "clang-block.h"

#ifdef __clang__

typedef void (^block_callback)(int counter);

static void try_local_block(block_callback callback)
{
    int i;
    for (i = 0; i < 3; i++) {
        callback(i);
    }
}

void test_block(void)
{
    __block int local_counter = 0;
    void (^local_block)(int counter) = ^(int counter) {
        printf("block counter = %d\n", counter);
        local_counter = counter;
    };

    try_local_block(local_block);
    printf("block local counter = %d\n", local_counter);
}

#else
void test_block(void)
{
}
#endif
