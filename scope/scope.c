#include <stdio.h>

int main(){
    int n=42;
    {
        int n=n/2;
        printf("n=%d\n",n);}
    printf("n=%d\n",n);
    return 0;}
