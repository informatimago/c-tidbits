#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    size_t length;
    char bytes[];
} array;

int main(){
    char bytes[80]="Hello world";
    // array a={80,(char[80]){}}; // auto-array.c:12:17: error: initialization of flexible array member is not allowed
    array a={0};
    array *ap=malloc(sizeof(*ap)+sizeof(bytes));
    ap->length=sizeof(bytes);
    strcpy(ap->bytes,bytes);
    printf("sizeof  a               = %lu\n",sizeof(a));
    printf("sizeof  ap              = %lu\n",sizeof(ap));
    printf("sizeof *ap              = %lu\n",sizeof(*ap));
    printf("sizeof *ap + ap->length = %lu\n",sizeof(*ap)+ap->length);
    return 0;}
