#include <stdio.h>


typedef void (*localfun_callback)(int counter);

static void try_local_function(localfun_callback callback)
{
    int i;
    for (i = 0; i < 10; i++) {
        callback(i);
    }
}

void test_local_function(void)
{
#ifdef HAS_LOCAL_FUNCTIONS
    int local_counter = 0;
    void local_function(int counter)
    {
        printf("localfun counter = %d\n", counter);
        local_counter = counter;
    }
    
    try_local_function(local_function);
    printf("localfun local counter = %d\n", local_counter);
#endif
}


