#include <stdio.h>

void f(int * const out){
    // static int* p=0;
    // static int  e=0;
    // out=&e;
    // out=p;
    (*out)=42;
}

void g(int const * out){
    static int* p=0;
    static int  e=0;
    out=&e;
    out=p;
    // (*out)=42;
}

void h(const int * out){
    static int* p=0;
    static int  e=0;
    out=&e;
    out=p;
    /* (*out)=42; */
}

int cmain(){
    int a=0;
    f(&a);
    return 0;
}
