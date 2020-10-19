#include <stdio.h>

#define msb(type) ((type)~((type)((type)(~(type)0) >> 1)))

int main(){
    printf("unsigned char      %x\n",msb(unsigned char));
    printf("unsigned short     %x\n",msb(unsigned short));
    printf("unsigned int       %x\n",msb(unsigned int));
    printf("unsigned long      %lx\n",msb(unsigned long));
    printf("unsigned long long %llx\n",msb(unsigned long long));
    return 0;}

/*
-*- mode: compilation; default-directory: "~/src/c/" -*-
Compilation started at Wed Jul 29 17:36:46

SRC="/Users/pjb/src/c/msb.c" ; EXE="msb" ; clang -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
unsigned char      80
unsigned short     8000
unsigned int       80000000
unsigned long      8000000000000000
unsigned long long 8000000000000000
status = 0

Compilation finished at Wed Jul 29 17:36:46

*/
