#include <stdio.h>
#include "lambda.h"

typedef void (
#if HAS_BLOCKS
              ^
#else
              *
#endif
              localfun_callback)(int counter);

static void try_local_function(localfun_callback callback)
{
    int i;
    for (i = 0; i < 10; i++) {
        callback(i);
    }
}

void test_lambda(void)
{
#if HAS_BLOCKS
    __block
#endif
            int local_counter = 0;
    void (^local_function)(int counter) = ^(int counter) {
        printf("lambda counter = %d\n", counter);
        local_counter = counter;
    };

    try_local_function(local_function);
    printf("lambda local counter = %d\n", local_counter);
}
