
#include <stdio.h>
#include <stdlib.h>


struct hab
{
    uint16_t a:1;
    uint16_t b:15;
} __attribute__((__packed__)) sab;


struct hba
{
    uint16_t b:15;
    uint16_t a:1;
} __attribute__((__packed__)) sba;



typedef unsigned char octet;

void dump_octet(octet byte){
    for(int i=7;i>=0;i--){
        printf("%d",0!=(byte&(1<<i)));
    }
    printf(" ");
}

void dump(void* address,unsigned int size){
    octet* bytes=address;
    for(unsigned int i=0;i<size;i++){
        dump_octet(bytes[i]);
    }
    printf("\n");
}




int main(){
    sab.a=1;
    sab.b=0;
    dump(&sab,sizeof(sab));
    sab.a=1;
    sab.b=0x5555;
    dump(&sab,sizeof(sab));
    sba.a=1;
    sba.b=0;
    dump(&sba,sizeof(sba));
    sba.a=1;
    sba.b=0x5555;
    dump(&sba,sizeof(sba));
    return 0;
}
