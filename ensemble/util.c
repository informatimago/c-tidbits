#include <util.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sysexits.h>

void error(const char* format,...){
    va_list ap;
    va_start(ap,format);
    vfprintf(stderr,format,ap);
    va_end(ap);
    exit(EX_DATAERR);}

void* check_memory(void* block){
    if(0==block){
        error("Out of memory\n");}
    return block;}

int convert_int(const char* text){
    int sign=1;
    int value=0;
    int i=0;
    switch(text[i]){
      case '-': sign=-1;  // fall thru
      case '+': i++;}
    while(text[i]){
        if(INT_MAX/10<value){
            // Note: since we compare with INT_MAX, we exclude INT_MIN.
            error("integer too big: %s",text);}
        value=value*10+digittoint(text[i]);
        i++;}
    return sign*value;}

