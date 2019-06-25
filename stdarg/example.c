#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int vf(int c,va_list ap){
    int result=0;
    while(0<c){
        result+=va_arg(ap,int);
        c--;
    }
    return result;
}

int f(int c,...){
    int result;
    va_list ap;
    va_start(ap,c);
    result=vf(c,ap);
    va_end(ap);
    return result;
}

typedef struct {
    int count;
    int values[10];
}  int_vector;

int my_own_vf(int_vector* args){
    int result=0;
    int i;
    for(i=0;i<args->count;i++){
        result+=args->values[i];
    }
    return result;
}
    

int main(int argc,char**argv){
    
    int_vector args;
    for(args.count=0;args.count<argc-1;args.count++){
        args.values[args.count]=atoi(argv[1+args.count]);
    }

    // So we can do this:
    printf("f(3,1,2,3)=%d\n",f(3,1,2,3));


    // but, oops!  How can we pass variable length array args as flat arguments to f?
    

    // So instead, we do it ourselves:
    printf("my_own_vf(&args)=%d\n",my_own_vf(&args));

    return 0;
}

/*
-*- mode: compilation; default-directory: "~/src/c/stdarg/" -*-
Compilation started at Sat Sep  1 14:34:07

SRC="/Users/pjb/src/c/stdarg/example.c" ; EXE="example" ; gcc -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} 5 1 2 3 4 5 && echo status = $?
f(3,1,2,3)=6
my_own_vf(&args)=20
status = 0

Compilation finished at Sat Sep  1 14:34:07
*/
