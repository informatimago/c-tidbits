#include <stdio.h>
#include "gcc-local-function.h"
#include "clang-block.h"
#include "lambda.h"

int main(void){
    test_local_function();
    test_block();
    test_lambda();
    return 0;
}
