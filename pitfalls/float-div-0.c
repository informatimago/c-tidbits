#include <stdio.h>

int main(){
    struct b {
        float m_inv;
    } body[]={0.0};
    double mass=1e-200;
    double INFINITY=1e20;
    printf("INFINITY    = %f\n",INFINITY);
    printf("mass        = %f\n",mass);
    body->m_inv = mass == 0.0f ? INFINITY : 1.0f/mass;
    printf("body->m_inv = %f\n",body->m_inv);
    return 0;
}

/*
-*- mode: compilation; default-directory: "~/src/c/pitfalls/" -*-
Compilation started at Fri May  3 01:34:30

SRC="/Users/pjb/src/c/pitfalls/float-div-0.c" ; EXE="float-div-0" ; gcc -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
INFINITY    = 100000000000000000000.000000
mass        = 0.000000
body->m_inv = inf
status = 0

Compilation finished at Fri May  3 01:34:30
*/
