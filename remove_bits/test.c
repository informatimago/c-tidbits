#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "remove_bits.h"
#include "print_binary.h"
    
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


int main(){
    test();
    return 0;}
