#include <stdio.h>
#include <stdarg.h>

/*
if c is char:
va_arg_1.c:6:17: warning: passing an object that undergoes default argument promotion to 'va_start' has undefined behavior
      [-Wvarargs]
    va_start(ap,c);
*/
void foo(int argcnt, int c, ...){
    va_list ap;
    va_start(ap,c);
    while(argcnt-->0){
        printf("%d ",va_arg(ap,int));}}


void foo_va(int i, char c, va_list l){
    // do something
}

int main(){
    return 0;}
