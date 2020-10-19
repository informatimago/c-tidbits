#include <stdio.h>
#include "y.h"

int a(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return y*2;}
int b(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return y*3;}
int c(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return y*4;}
int d(int y){printf("%s::%s()\n",__FILE__,__FUNCTION__);return y*5;}

