#include <stdio.h>
/*
#define ENCLOSE_VARS(var,...)  typeof(var) var; ENCLOSE_VARS(__VA_ARGS__)
#define enclose(name,fun,var,...)                                       \
struct {                                                            \
typeof(fun) * fun;                                              \
ENCLOSE_VARS(var, __VA_ARGS__)                                  \
} name = { fun, var, __VA_ARGS__ }

int g(int x,int y){
return x+y;}

int f(int x){
int y=33;
enclose(g_closure,g,x,y);
return g_closure.fun(g_closure.x,g_closure.y);}
*/

int main(){
    // printf("f(42) = %d\n", f(42));
    return 0;}
