#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_substring(const char* string,size_t start,size_t end){
    size_t len=strlen(string);
    if(end>len){
        end=len;}
    if(start<end){
        if(end<len){
            if(start<end){
                char* buffer=malloc(end-start+1);
                strncpy(buffer,string+start,end-start);
                buffer[end-start]=0;
                printf("%s",buffer);
                free(buffer);}
            else{
                printf("%s",string+start);}}
        else{
            printf("%s",string+start);}}}

int main(){
    const char* hw="Hello World!";
    print_substring(hw,0,100); printf("\n");
    print_substring(hw,6,100); printf("\n");
    print_substring(hw,6,11);  printf("\n");
    print_substring(hw,6,6);   printf("\n");
    return 0;}

/*
-*- mode: compilation; default-directory: "~/src/c/print/" -*-
Compilation started at Fri Aug 21 20:07:24

SRC="/Users/pjb/src/c/print/print.c" ; EXE="print" ; clang -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
Hello World!
World!
World

status = 0

Compilation finished at Fri Aug 21 20:07:24

*/
