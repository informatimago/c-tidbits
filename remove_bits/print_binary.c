#include "print_binary.h"

void fprint_binary(FILE* output,unsigned width,unsigned value,unsigned flag){
    if(print_binary_prefix&flag){
        fprintf(output,"0b");}
    for(unsigned bit=1<<(width-1);bit!=0;bit>>=1){
        fprintf(output,"%c",(value&bit)?'1':'0');}}

void print_binary(unsigned width,unsigned value,unsigned flag){
    fprint_binary(stdout,width,value,flag);}
