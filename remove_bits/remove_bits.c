#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned char octet;

octet remove_bits(octet source,octet mask){
    octet result=0;
    for(unsigned m=1,bit=1;m<=UCHAR_MAX;m<<=1){
        if(m&mask){
            if(m&source){
                result|=bit;}
            bit<<=1;}}
    return result;}



enum {print_binary_prefix=1};
void fprint_binary(FILE* output,unsigned width,unsigned value,unsigned flag){
    if(print_binary_prefix&flag){
        fprintf(output,"0b");}
    for(unsigned bit=1<<(width-1);bit!=0;bit>>=1){
        fprintf(output,"%c",(value&bit)?'1':'0');}}
    

int test_success;
int test_failure;

void test_begin(){
    test_success=0;
    test_failure=0;}

void test_end(){
    printf("%8d tests\n",test_success+test_failure);
    printf("%8d successes\n",test_success);
    printf("%8d failures\n",test_failure);}

void check_remove_bits(octet source,octet mask,octet expected){
    octet result=remove_bits(source,mask);
    if(result==expected){
        test_success++;}
    else{
        test_failure++;
        fprintf(stdout,"FAILURE: remove_bits(");
        fprint_binary(stdout,CHAR_BIT,source,print_binary_prefix);
        fprintf(stdout,",");
        fprint_binary(stdout,CHAR_BIT,mask,print_binary_prefix);
        fprintf(stdout,") -> ");
        fprint_binary(stdout,CHAR_BIT,result,print_binary_prefix);
        fprintf(stdout,", expected ");
        fprint_binary(stdout,CHAR_BIT,expected,print_binary_prefix);
        fprintf(stdout,"\n");}}

void test(){
    test_begin();
    check_remove_bits(0b11111111,0b00000000,0b00000000);

    check_remove_bits(0b11111111,0b10000000,0b00000001);
    check_remove_bits(0b11111111,0b01000000,0b00000001);
    check_remove_bits(0b11111111,0b00100000,0b00000001);
    check_remove_bits(0b11111111,0b00010000,0b00000001);
    check_remove_bits(0b11111111,0b00001000,0b00000001);
    check_remove_bits(0b11111111,0b00000100,0b00000001);
    check_remove_bits(0b11111111,0b00000010,0b00000001);
    check_remove_bits(0b11111111,0b00000001,0b00000001);

    check_remove_bits(0b11111111,0b10000001,0b00000011);
    check_remove_bits(0b11111111,0b01000001,0b00000011);
    check_remove_bits(0b11111111,0b00100001,0b00000011);
    check_remove_bits(0b11111111,0b00010001,0b00000011);
    check_remove_bits(0b11111111,0b00001001,0b00000011);
    check_remove_bits(0b11111111,0b00000101,0b00000011);
    check_remove_bits(0b11111111,0b00000011,0b00000011);

    check_remove_bits(0b11110000,0b10000000,0b00000001);
    check_remove_bits(0b11110000,0b01000000,0b00000001);
    check_remove_bits(0b11110000,0b00100000,0b00000001);
    check_remove_bits(0b11110000,0b00010000,0b00000001);
    check_remove_bits(0b11110000,0b00001000,0b00000000);
    check_remove_bits(0b11110000,0b00000100,0b00000000);
    check_remove_bits(0b11110000,0b00000010,0b00000000);
    check_remove_bits(0b11110000,0b00000001,0b00000000);

    check_remove_bits(0b11110000,0b10000001,0b00000010);
    check_remove_bits(0b11110000,0b01000001,0b00000010);
    check_remove_bits(0b11110000,0b00100001,0b00000010);
    check_remove_bits(0b11110000,0b00010001,0b00000010);
    check_remove_bits(0b11110000,0b00001001,0b00000000);
    check_remove_bits(0b11110000,0b00000101,0b00000000);
    check_remove_bits(0b11110000,0b00000011,0b00000000);


    check_remove_bits(0b10101010,0b11111111,0b10101010);
    check_remove_bits(0b10101010,0b11111110,0b01010101);
    check_remove_bits(0b10101010,0b11111100,0b00101010);
    check_remove_bits(0b10101010,0b11111000,0b00010101);
    check_remove_bits(0b10101010,0b11110000,0b00001010);
    check_remove_bits(0b10101010,0b11100000,0b00000101);
    check_remove_bits(0b10101010,0b11000000,0b00000010);
    check_remove_bits(0b10101010,0b10000000,0b00000001);

    check_remove_bits(0b10101111,0b11111111,0b10101111);
    check_remove_bits(0b10101111,0b11111110,0b01010111);
    check_remove_bits(0b10101111,0b11111100,0b00101011);
    check_remove_bits(0b10101111,0b11111000,0b00010101);
    check_remove_bits(0b10101111,0b11110000,0b00001010);
    check_remove_bits(0b10101111,0b11100000,0b00000101);
    check_remove_bits(0b10101111,0b11000000,0b00000010);
    check_remove_bits(0b10101111,0b10000000,0b00000001);

    check_remove_bits(0b10101010,0b10101010,0b00001111);
    check_remove_bits(0b10101010,0b01010101,0b00000000);
    test_end();}


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


int main(int argc,char** argv){
    int do_test=0;
    int do_generate=0;
    for(int i=1;i<argc;i++){
        if(0==strcmp(argv[i],"--test")){
            do_test=1;}
        else if(0==strcmp(argv[i],"--generate")){
            do_generate=1;}}

    if(do_test){
        test();}

    if(do_generate){
        generate();}
    
    return 0;}
