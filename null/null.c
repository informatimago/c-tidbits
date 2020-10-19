#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void f(){
    static int* p;
    static int* q;
    static int* h;
    p=0;
    q=(void*)(intptr_t)0xdeadface;
    h=(int*)0xffffff01;
}


int main(){
    f();
    return 0;}
