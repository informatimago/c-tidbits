#include <stdio.h>
#include "xw.h"
#include "x.h"

int x_a(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return a(x);}
int x_b(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return b(x);}

