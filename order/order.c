#include <stdio.h>

int f(int x){
    printf("%s(%d)\n",__FUNCTION__,x);
    return 2*x;}

int g(int x){
    printf("%s(%d)\n",__FUNCTION__,x);
    return x+x;}

int main(){
    int x=f(2)+g(2);
    printf("result=%d\n",x);
    return 0;}
