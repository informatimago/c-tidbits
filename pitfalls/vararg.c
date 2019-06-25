#include <stdarg.h>
#include <stdio.h>

int count_args(void* first,...){
    va_list args;
    va_start(args,first);
    int count=1;
    void* p=va_arg(args,void*);
    while(p!=NULL){
        count++;
        p=va_arg(args,void*);}
    return count;}


int main(){
    char* a="hello";
    char* b="world";
    char* c="morning";
    printf("3 args with NULL -> %d\n",count_args(a,b,c,NULL));
    printf("2 args with NULL -> %d\n",count_args(a,b,NULL));
    printf("3 args with NULL -> %d\n",count_args(a,b,c,NULL));
    printf("2 args with 0    -> %d\n",count_args(a,b,0,NULL));

    printf("13 args with NULL -> %d\n",count_args(a,b,c,a,b,c,a,b,c,a,b,c,a,NULL));
    printf("12 args with NULL -> %d\n",count_args(a,b,c,a,b,c,a,b,c,a,b,c,NULL));
    printf("13 args with NULL -> %d\n",count_args(a,b,c,a,b,c,a,b,c,a,b,c,a,NULL));
    printf("12 args with 0    -> %d\n",count_args(a,b,c,a,b,c,a,b,c,a,b,c,0,NULL));
    return 0;}
