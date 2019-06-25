#include <stdio.h>
#include <string.h>

int main(int argc,char** argv){
    long foo=42;
    char buffer[16];
    long bar=33;
    strcpy(buffer,argv[1]);
    printf("%s\n",buffer);
    printf("foo should be 42, it is: %ld\n",foo);
    printf("bar should be 33, it is: %ld\n",bar);
    return 0;}
