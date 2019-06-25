#include <stdlib.h>
#include <stdio.h>

void foo(void);
void bar(void);
void quux(void*);
void baz(void*);

typedef void (*void_fun)(void);
typedef void (*pointer_fun)(void*);

typedef struct {
    enum { f_void, f_pointer } type;
    union {
          void_fun    f_void_fun;
          pointer_fun f_pointer_fun;
    } fun;
}  typed_fun;

void call(typed_fun* fun){
    switch(fun->type){
      case f_void:    fun->fun.f_void_fun(); break;
      case f_pointer: fun->fun.f_pointer_fun(NULL); break;}}

typed_fun funs[]={
    { .type=f_void, .fun.f_void_fun=foo },
    { .type=f_void, .fun.f_void_fun=bar },
    { .type=f_pointer, .fun.f_pointer_fun=quux },
    { .type=f_pointer, .fun.f_pointer_fun=baz }};

#define countof(a) (sizeof(a)/(sizeof(a[0])))

int main(){
    for(int i=0;i<countof(funs);i++){
        call(&funs[i]);}
    return 0;}


void foo(void){printf("%s()\n",__FUNCTION__);}
void bar(void){printf("%s()\n",__FUNCTION__);}
void quux(void*arg){printf("%s(%p)\n",__FUNCTION__,arg);}
void baz(void*arg){printf("%s(%p)\n",__FUNCTION__,arg);}


/*
-*- mode: compilation; default-directory: "/tmp/" -*-
Compilation started at Sat Jan  5 16:10:03

SRC="/tmp/f.c" ; EXE="f" ; gcc -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
foo()
bar()
quux(0x0)
baz(0x0)
status = 0

Compilation finished at Sat Jan  5 16:10:03
*/
