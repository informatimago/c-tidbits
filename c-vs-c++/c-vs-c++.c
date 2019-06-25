#include <stdio.h>

void main(void) {
 	int c=3;
    int cpp=c++;
 	printf("C++ = %d\n", cpp);
 	printf("C   = %d\n", c);
 	printf("C %s C++\n", (c<cpp)?"<":((c>cpp)?">":"=="));
}
