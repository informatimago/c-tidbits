
#include <stdio.h>
#include <string.h>

int main() {
    int i = 1; int j = 2;
    int * p = &i + 1; int * q = &j;
    if(!memcmp( &p, &q, sizeof( p ))){
        *p = 3;
        printf( "%d %d\n", *p, *q );
    }else{
        printf( "different pointers\n");
    }}
    
