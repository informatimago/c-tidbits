#include <stdlib.h>
#include <stdint.h>
#include <sysexits.h>
#include <stdio.h>

void* check_pointer(void* pointer){
    if(pointer) return pointer;
    fprintf(stderr,"Out of memory\n");
    exit(EX_OSERR);}

typedef char* cstring;

cstring binary_representation_uint32_t(uint32_t n){
    cstring result=check_pointer(malloc(33));
    for(int bit=1,i=31;0<=i;bit<<=1,i--){
        result[i]=(n&bit)?'1':'0';}
    result[32]='\0';
    return result;}

int main(){
    printf("%s | %s = %s\n",
           binary_representation_uint32_t(0b100100000),
           binary_representation_uint32_t(0b000000100),
           binary_representation_uint32_t(0b100100000|0b000000100));
    return 0;}

/*
-*- mode: compilation; default-directory: "~/src/c/" -*-
Compilation started at Wed Sep 16 02:11:07

SRC="/Users/pjb/src/c/binary.c" ; EXE="binary" ; clang  -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
00000000000000000000000100100000 | 00000000000000000000000000000100 = 00000000000000000000000100100100
status = 0

Compilation finished at Wed Sep 16 02:11:07

*/
