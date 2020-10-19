#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrayset(size_t array_count,void* array,size_t element_size,void* element){
    for(int i=0;i<array_count;i++){
        memcpy(array,element,element_size);
        array=((char*)array)+element_size;}}

int main(){
    size_t count=10;
    int* array=malloc(count*sizeof(*array));
    int init=42;
    arrayset(count,array,sizeof(init),&init);
    for(int i=0;i<count;i++){
        printf("%d ",array[i]);}
    printf("\n");
    return(0);}

/*
-*- mode: compilation; default-directory: "~/src/c/arrayset/" -*-
Compilation started at Mon Sep  7 02:39:36

SRC="/Users/pjb/src/c/arrayset/arrayset.c" ; EXE="arrayset" ; clang  -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
42 42 42 42 42 42 42 42 42 42 
status = 0

Compilation finished at Mon Sep  7 02:39:36

*/
