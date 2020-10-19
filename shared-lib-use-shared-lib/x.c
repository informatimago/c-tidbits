#include <stdio.h>
#include "x.h"

int a(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return x+2;}
int b(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return x+3;}
int c(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return x+4;}
int d(int x){printf("%s::%s()\n",__FILE__,__FUNCTION__);return x+5;}

