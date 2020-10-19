#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "remove_bits.h"
#include "print_binary.h"
    

void generate(){
    int max1=1<<CHAR_BIT;
    printf("typedef unsigned char octet;\n");
    printf("octet remove_bits(octet source,octet mask){\n");
    printf("    static octet table[%d][%d]={\n",max1,max1);
    for(int m=0;m<max1;m++){
        printf("      {");
        for(int s=0;s<max1;s++){
            octet result=remove_bits((octet)s,(octet)m);
            printf("%u,",result);}
        printf("},\n");}
    printf("    };\n");
    printf("    return table[mask][source];\n");
    printf("}\n");}


int main(){
    generate();
    return 0;}
