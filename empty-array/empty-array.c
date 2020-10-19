#include <stdio.h>

void f(int* p){
    printf("%p\n",p);
}

int main(void){
    int a[0];
    int* p=a;
    f(p);
    f(a);
    return 0;}
