#include <stdio.h>

void f(int* p){
    printf("%p\n",p);
}

int main(void){
    int a[0];
    int* p=a;
    f(p);
    f(a);
}

0x7fff505aca4c
0x7fff505aca4c
