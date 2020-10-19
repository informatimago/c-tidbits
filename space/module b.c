#include <stdio.h>
#include "module b.h"
#include "module a.h"

int module_b_f(int x){
    printf("%s x=%d\n",__FUNCTION__,x);
    return 3+module_a_f(x);}

    
