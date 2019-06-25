#include <stdlib.h>
#include <stdio.h>

void dump(void* memory,int size){
    int i;
    unsigned char* bytes=memory;
    for(i=0;i<size;i++){
        if(i%16==0){
            printf("\n%16p: ",memory+i);
        }
        printf("%02x ",bytes[i]);
    }
    printf("\n");
}

int main(){
    int i;
    int size=10;
    int (*a)[]=malloc(size*sizeof(int));
    for(i=0;i<size;i++){
        (*a)[i]=0x01010101*(1+i);
    }
    int* b=malloc(size*sizeof(int));
    for(i=0;i<size;i++){
        b[i]=0x01010101*(1+i);
    }
    int** c=malloc(size*sizeof(int*));
    for(i=0;i<size;i++){
        c[i]=malloc(sizeof(int));
        *c[i]=0x01010101*(1+i);
    }
    dump(a,size*sizeof(int));
    dump(b,size*sizeof(int));
    dump(c,size*sizeof(int*));
    for(i=0;i<size;i++){
        dump(c[i],sizeof(int));
    }
    return 0;
}


/*
-*- mode: compilation; default-directory: "/tmp/" -*-
Compilation started at Mon Jul  9 22:27:21

SRC="/tmp/a.c" ; EXE="a" ; gcc -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?

  0x7fd531c02820: 01 01 01 01 02 02 02 02 03 03 03 03 04 04 04 04 
  0x7fd531c02830: 05 05 05 05 06 06 06 06 07 07 07 07 08 08 08 08 
  0x7fd531c02840: 09 09 09 09 0a 0a 0a 0a 

  0x7fd531c02850: 01 01 01 01 02 02 02 02 03 03 03 03 04 04 04 04 
  0x7fd531c02860: 05 05 05 05 06 06 06 06 07 07 07 07 08 08 08 08 
  0x7fd531c02870: 09 09 09 09 0a 0a 0a 0a 

  0x7fd531c02880: d0 28 c0 31 d5 7f 00 00 e0 28 c0 31 d5 7f 00 00 
  0x7fd531c02890: f0 28 c0 31 d5 7f 00 00 00 29 c0 31 d5 7f 00 00 
  0x7fd531c028a0: 10 29 c0 31 d5 7f 00 00 20 29 c0 31 d5 7f 00 00 
  0x7fd531c028b0: 30 29 c0 31 d5 7f 00 00 40 29 c0 31 d5 7f 00 00 
  0x7fd531c028c0: 50 29 c0 31 d5 7f 00 00 60 29 c0 31 d5 7f 00 00 

  0x7fd531c028d0: 01 01 01 01 

  0x7fd531c028e0: 02 02 02 02 

  0x7fd531c028f0: 03 03 03 03 

  0x7fd531c02900: 04 04 04 04 

  0x7fd531c02910: 05 05 05 05 

  0x7fd531c02920: 06 06 06 06 

  0x7fd531c02930: 07 07 07 07 

  0x7fd531c02940: 08 08 08 08 

  0x7fd531c02950: 09 09 09 09 

  0x7fd531c02960: 0a 0a 0a 0a 
status = 0

Compilation finished at Mon Jul  9 22:27:21

*/
