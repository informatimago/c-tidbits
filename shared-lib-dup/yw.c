#include <stdio.h>
#include "yw.h"
#include "y.h"

int y_c(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return c(y);}
int y_d(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return d(y);}

