#include <stdio.h>
#include "module a.h"

int module_a_f(int x){
    printf("%s x=%d\n",__FUNCTION__,x);
    return 2*x;}

    
