#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char** argv){
    union u { int i; void *p; } a, b;
    a.p=&a;
    b.p=malloc(2);
    a.i=42;
    b.i=42;
    printf("memcmp = %d\n", memcmp(&a, &b, sizeof (union u)));
    return 0;}
    
/*
-*- mode: compilation; default-directory: "~/src/c-tidbits/union-memcmp/" -*-
Compilation started at Thu Apr 21 23:36:14

SRC="/Users/pjb/src/c-tidbits/union-memcmp/union-memcmp.c" ; EXE="union-memcmp" ; clang  -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
memcmp = 247
status = 0

Compilation finished at Thu Apr 21 23:36:14
*/
