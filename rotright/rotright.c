#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#define gen_rotright(type)                                              \
    type rotright_##type(type n,int pos){                               \
        const int width=(sizeof(type)*CHAR_BIT);                        \
        type bottom_mask=(1<<pos)-1;                                    \
        type middle_mask=(1<<(width-pos))-1;                            \
        type up=n&bottom_mask;                                          \
        return ((n>>pos)&middle_mask)|(up<<(width-pos));}

gen_rotright(uint8_t)
gen_rotright(uint16_t)
gen_rotright(uint32_t)
gen_rotright(uint64_t)
gen_rotright(int8_t)
gen_rotright(int16_t)
gen_rotright(int32_t)
gen_rotright(int64_t)

#define rotright(n,pos) _Generic(n,                                     \
                                 uint8_t:rotright_uint8_t(n,pos),       \
                                 uint16_t:rotright_uint16_t(n,pos),     \
                                 uint32_t:rotright_uint32_t(n,pos),     \
                                 uint64_t:rotright_uint64_t(n,pos),     \
                                 int8_t:rotright_int8_t(n,pos),         \
                                 int16_t:rotright_int16_t(n,pos),       \
                                 int32_t:rotright_int32_t(n,pos),       \
                                 int64_t:rotright_int64_t(n,pos))

#define test(type,format,n,pos,expected)                                                                \
    do{                                                                                                 \
        type var=n;                                                                                     \
        type res=rotright(var,pos);                                                                     \
        type exp=expected;                                                                              \
        if(res==exp){                                                                                   \
            printf("SUCCESS   rotright("format",%d)="format"\n",var,pos,res);}                          \
        else{                                                                                           \
            printf("FAILURE   rotright("format",%d)="format", expected "format"\n",var,pos,res,exp);}   \
    }while(0)

int main(){
    test(uint8_t,"%hhu",0b10100101,4,0b01011010);
    test(uint8_t,"%hhu",0b10100101,1,0b11010010);
    test(uint16_t,"%hu",0b1010010100001111,4,0b1111101001010000);
    test(uint16_t,"%hu",0b1010010100001111,1,0b1101001010000111);
    // Add more tests.
    return 0;}


/*
-*- mode: compilation; default-directory: "~/src/c/" -*-
Compilation started at Sat Aug 22 21:56:00

SRC="/Users/pjb/src/c/rotright.c" ; EXE="rotright" ; clang -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
SUCCESS   rotright(165,4)=90
SUCCESS   rotright(165,1)=210
SUCCESS   rotright(42255,4)=64080
SUCCESS   rotright(42255,1)=53895
status = 0

Compilation finished at Sat Aug 22 21:56:00

*/
