// -*- mode:c;coding:utf-8 -*-
//****************************************************************************
//FILE:               sarith.c
//LANGUAGE:           C
//SYSTEM:             POSIX
//USER-INTERFACE:     NONE
//DESCRIPTION
//    
//    Defines a safe C arithmetic API.
//    
//AUTHORS
//    <PJB> Pascal J. Bourguignon <pjb@informatimago.com>
//MODIFICATIONS
//    2020-08-11 <PJB> Created.
//BUGS
//LEGAL
//    AGPL3
//    
//    Copyright Pascal J. Bourguignon 2020 - 2020
//    
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//    
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//    
//    You should have received a copy of the GNU Affero General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <assert.h>


#include <stdint.h>
#include <limits.h>


#ifdef GCC

typedef __int128          int128_t;
typedef unsigned __int128 uint128_t;

// There is no support in GCC for expressing an integer constant of type __int128
// for targets with long long integer less than 128 bits wide.

/* #ifndef INT128_MIN */
/* #define INT128_MIN  0x800000000000000000000000LL */
/* #endif */
/* #ifndef INT128_MAX */
/* #define INT128_MAX  0x7fffffffffffffffffffffffLL */
/* #endif */
/* #ifndef UINT128_MAX */
/* #define UINT128_MAX 0xffffffffffffffffffffffffLLU */
/* #endif */

#endif

#ifdef GCC
#define genop(op,a,b) _Generic((a),                                     \
                               uint8_t:   u8##op,                       \
                               uint16_t:  u16##op,                      \
                               uint32_t:  u32##op,                      \
                               uint64_t:  u64##op,                      \
                               uint128_t: u128##op,                     \
                               int8_t:    i8##op,                       \
                               int16_t:   i16##op,                      \
                               int32_t:   i32##op,                      \
                               int64_t:   i64##op,                      \
                               int128_t:  i128##op,                     \
                               float:     f##op,                        \
                               double:    d##op)(a,b)
#else
#define genop(op,a,b) _Generic((a),                                     \
    uint8_t:   u8##op,                                                  \
    uint16_t:  u16##op,                                                 \
    uint32_t:  u32##op,                                                 \
    uint64_t:  u64##op,                                                 \
                               int8_t:    i8##op,                       \
                               int16_t:   i16##op,                      \
                               int32_t:   i32##op,                      \
                               int64_t:   i64##op,                      \
                               float:     f##op,                        \
                               double:    d##op)(a,b)
#endif

#define add(a,b) genop(add,a,b)
#define sub(a,b) genop(sub,a,b)
#define mul(a,b) genop(mul,a,b)
#define div(a,b) genop(div,a,b)
#define mod(a,b) genop(mod,a,b)

typedef enum {
    BcArithmetic_operation_add,
    BcArithmetic_operation_sub,
    BcArithmetic_operation_mul,
    BcArithmetic_operation_div,
    BcArithmetic_operation_mod,
}  BcArithmetic_operation;

typedef enum {
    BcArithmetic_typetag_uint8_t,
    BcArithmetic_typetag_uint16_t,
    BcArithmetic_typetag_uint32_t,
    BcArithmetic_typetag_uint64_t,
#ifdef GCC
    BcArithmetic_typetag_uint128_t,
#endif
    BcArithmetic_typetag_int8_t,
    BcArithmetic_typetag_int16_t,
    BcArithmetic_typetag_int32_t,
    BcArithmetic_typetag_int64_t,
#ifdef GCC
    BcArithmetic_typetag_int128_t,
#endif
    BcArithmetic_typetag_float,
    BcArithmetic_typetag_double,
}  BcArithmetic_typetag;

typedef struct {
    BcArithmetic_typetag typetag;
    union {
        uint8_t v_uint8_t;
        uint16_t v_uint16_t;
        uint32_t v_uint32_t;
        uint64_t v_uint64_t;
        int8_t v_int8_t;
        int16_t v_int16_t;
        int32_t v_int32_t;
        int64_t v_int64_t;
#ifdef GCC
        uint128_t v_uint128_t;
        int128_t v_int128_t;
#endif
        float    v_float;
        double   v_double;
    } value;
}    BcArithmetic_argument;

typedef enum {
    BcArithmetic_success,
    BcArithmetic_error_overflow,
    BcArithmetic_error_underflow,
    BcArithmetic_error_divide_by_zero,
}    BcArithmetic_error;

const char* BcArithmetic_operation_label[]={"add","sub","mul","div","mod"};
const char* BcArithmetic_error_label[]={"success","overflow","underflow","divide-by-zero"};
const struct { const char* name; const char* format; } BcArithmetic_tagdata[]={
    {"uint8_t",   "%hhu"},
    {"uint16_t",  "%hu"},
    {"uint32_t",  "%u"},
    {"uint64_t",  "%lu"},
    {"uint128_t", "%llu"},
    {"int8_t",    "%hhd"},
    {"int16_t",   "%hd"},
    {"int32_t",   "%d"},
    {"int64_t",   "%ld"},
    {"int128_t",  "%lld"},
    {"float",     "%e"},
    {"double",    "%e"},
};

void BcArithmetic_signal_error(BcArithmetic_error error,
                               BcArithmetic_operation operation,
                               int narguments,
                               const BcArithmetic_argument* arguments);
#if DEBUG
#define GENDEBUG(x) x
#else
#define GENDEBUG(x) do{}while(0)
#endif

// for unsigned operations, a single check is needed:
#define gencheck1fun(type,stem,name,op,check,error)                     \
    type stem##name(type a,type b){                                     \
        GENDEBUG(fprintf(stderr,"%s: %s -> %d\n",#type,#check,check));  \
        if(check){                                                      \
            static BcArithmetic_argument args[2];                       \
            args[0].typetag=BcArithmetic_typetag_##type;                \
            args[0].value.v_##type=a;                                   \
            args[1].typetag=BcArithmetic_typetag_##type;                \
            args[1].value.v_##type=b;                                   \
            fprintf(stderr,"%s: %s -> %d\n",#type,#check,check);        \
            BcArithmetic_signal_error(BcArithmetic_error_##error,       \
                                      BcArithmetic_operation_##name,    \
                                      2,                                \
                                      args);}                           \
        return op;}

// for signed operations, a two checks are needed:
#define gencheck2fun(type,stem,name,op,check1,error1,check2,error2)         \
    type stem##name(type a,type b){                                         \
        GENDEBUG(fprintf(stderr,"%s: %s -> %d\n",#type,#check1,check1));    \
        GENDEBUG(fprintf(stderr,"%s: %s -> %d\n",#type,#check2,check2));    \
        if(check1){                                                         \
            static BcArithmetic_argument args[3];                           \
            args[0].typetag=BcArithmetic_typetag_##type;                    \
            args[0].value.v_##type=a;                                       \
            args[1].typetag=BcArithmetic_typetag_##type;                    \
            args[1].value.v_##type=b;                                       \
            args[2].typetag=BcArithmetic_typetag_##type;                    \
            args[2].value.v_##type=op;                                      \
            fprintf(stderr,"%s: %s -> %d\n",#type,#check1,check1);          \
            BcArithmetic_signal_error(BcArithmetic_error_##error1,          \
                                      BcArithmetic_operation_##name,        \
                                      3,                                    \
                                      args);}                               \
        else if(check2){                                                    \
            static BcArithmetic_argument args[3];                           \
            args[0].typetag=BcArithmetic_typetag_##type;                    \
            args[0].value.v_##type=a;                                       \
            args[1].typetag=BcArithmetic_typetag_##type;                    \
            args[1].value.v_##type=b;                                       \
            args[2].typetag=BcArithmetic_typetag_##type;                    \
            args[2].value.v_##type=op;                                      \
            fprintf(stderr,"%s: %s -> %d\n",#type,#check2,check2);          \
            BcArithmetic_signal_error(BcArithmetic_error_##error2,          \
                                      BcArithmetic_operation_##name,        \
                                      3,                                    \
                                      args);}                               \
        return op;}



// Definition of the checked operations:


#define genufun(stem,type,max)                                                                  \
    gencheck1fun(type, stem, add, a+b, b>max-a, overflow)                                       \
    gencheck1fun(type, stem, sub, a-b, b>a,     underflow)                                      \
    gencheck1fun(type, stem, mul, a*b, ((b>0)&&(a>(max/b))) || ((a>0)&&(b>(max/a))), overflow)  \
    gencheck1fun(type, stem, div, a/b, (b==0), divide_by_zero)                                  \
    gencheck1fun(type, stem, mod, a%b, (b==0), divide_by_zero)

#define genifun(stem,type,min,max)                                                      \
    gencheck2fun(type, stem, add, a+b,                                                  \
                 ((a<0)&&(min-a>b)), underflow,                                         \
                 ((a>0)&&(b>max-a)), overflow)                                          \
    gencheck2fun(type, stem, sub, a-b,                                                  \
                 ((b>0)&&(min+b>a)), underflow,                                         \
                 ((b<0)&&(a>max+b)), overflow)                                          \
    gencheck2fun(type, stem, mul, a*b,                                                  \
                 (((a<0)&&(b<0)&&(max/a<b)) || ((a>0)&&(b>0)&&(max/a>b))), overflow,    \
                 (((a<0)&&(b>0)&&(min/a<b)) || ((a>0)&&(b<0)&&(min/a>b))), underflow)   \
    gencheck2fun(type, stem, div, a/b,                                                  \
                 (b==0), divide_by_zero,                                                \
                 ((b==-1)&&(a==min)), overflow)                                         \
    gencheck2fun(type, stem, mod, a%b,                                                  \
                 (b==0), divide_by_zero,                                                \
                 ((b==-1)&&(a==min)), overflow)                                         \
    // TODO: ((b==-1)&&(a==min)) works only for 2-complement, ie when -MIN=MAX+1

#ifdef GCC
#define genfuns()                                                       \
    genufun(u8,uint8_t,UINT8_MAX)                                       \
    genufun(u16,uint16_t,UINT16_MAX)                                    \
    genufun(u32,uint32_t,UINT32_MAX)                                    \
    genufun(u64,uint64_t,UINT64_MAX)                                    \
    genifun(i8,int8_t,INT8_MIN,INT8_MAX)                                \
    genifun(i16,int16_t,INT16_MIN,INT16_MAX)                            \
    genifun(i32,int32_t,INT32_MIN,INT32_MAX)                            \
    genifun(i64,int64_t,INT64_MIN,INT64_MAX)                            \
    genufun(u128,uint128_t,UINT128_MAX)                                 \
    genifun(i128,int128_t,INT128_MIN,INT128_MAX) 
#else
#define genfuns()                                                       \
    genufun(u8,uint8_t,UINT8_MAX)                                       \
    genufun(u16,uint16_t,UINT16_MAX)                                    \
    genufun(u32,uint32_t,UINT32_MAX)                                    \
    genufun(u64,uint64_t,UINT64_MAX)                                    \
    genifun(i8,int8_t,INT8_MIN,INT8_MAX)                                \
    genifun(i16,int16_t,INT16_MIN,INT16_MAX)                            \
    genifun(i32,int32_t,INT32_MIN,INT32_MAX)                            \
    genifun(i64,int64_t,INT64_MIN,INT64_MAX) 
#endif

genfuns()
    
float fadd(float a,float b){return a+b;}
float fsub(float a,float b){return a-b;}
float fmul(float a,float b){return a*b;}
float fdiv(float a,float b){return a/b;}


double dadd(double a,double b){return a+b;}
double dsub(double a,double b){return a-b;}
double dmul(double a,double b){return a*b;}
double ddiv(double a,double b){return a/b;}
double dint(double x){return x;}
double dmod(double a,double b){return a-dint(a/b)*b;}

void fprint_argument(FILE* out,const BcArithmetic_argument* argument){
    fprintf(out,"%s ",BcArithmetic_tagdata[argument->typetag].name);
    switch(argument->typetag){
#define typetag_case(type)                                              \
        case BcArithmetic_typetag_##type:                               \
            fprintf(out,BcArithmetic_tagdata[argument->typetag].format, \
                    argument->value.v_##type);                          \
            break
        typetag_case(uint8_t);
        typetag_case(uint16_t);
        typetag_case(uint32_t);
        typetag_case(uint64_t);
        typetag_case(int8_t);
        typetag_case(int16_t);
        typetag_case(int32_t);
        typetag_case(int64_t);
#ifdef GCC
        typetag_case(uint128_t);
        typetag_case(int128_t);
#endif        
        typetag_case(float);
        typetag_case(double);}}

void BcArithmetic_report_error(BcArithmetic_error error,
                               BcArithmetic_operation operation,
                               int narguments,
                               const BcArithmetic_argument* arguments){
    fprintf(stderr,"%s error: %s",
            BcArithmetic_error_label[error],
            BcArithmetic_operation_label[operation]);
    if(narguments>0){
        const char* delim="(";
        for(int i=0;i<narguments;i++,delim=","){
            fprintf(stderr,"%s",delim);
            fprint_argument(stderr,&arguments[i]);}
        fprintf(stderr,")\n");}}

void BcArithmetic_default_error_handler(BcArithmetic_error error,
                                        BcArithmetic_operation operation,
                                        int narguments,
                                        const BcArithmetic_argument* arguments){
    BcArithmetic_report_error(error,operation,narguments,arguments);
    exit(1);}

typedef void (*BcArithmetic_errorhandler_pr)(BcArithmetic_error error,
                                             BcArithmetic_operation operation,
                                             int narguments,
                                             const BcArithmetic_argument* arguments);

// TODO: make BcArithmetic_error_handler thread-specific.
BcArithmetic_errorhandler_pr BcArithmetic_error_handler=BcArithmetic_default_error_handler;

void BcArithmetic_signal_error(BcArithmetic_error error,
                               BcArithmetic_operation operation,
                               int narguments,
                               const BcArithmetic_argument* arguments){
    BcArithmetic_error_handler(error,operation,narguments,arguments);}

jmp_buf test_jump;
BcArithmetic_error test_error=BcArithmetic_success;
void test_error_handler(BcArithmetic_error error,
                        BcArithmetic_operation operation,
                        int narguments,
                        const BcArithmetic_argument* arguments){
    test_error=error;
    BcArithmetic_report_error(error,operation,narguments,arguments);
    longjmp(test_jump,test_error);}

int main(){

#define plimit(fmt,limit) printf("%-12s = "fmt"\n",#limit,limit);
    plimit("%24u",UINT8_MAX);
    plimit("%24u",UINT16_MAX);
    plimit("%24u",UINT32_MAX);
    plimit("%24llu",UINT64_MAX);
    plimit("%24d",INT8_MIN);      plimit("%24d",INT8_MAX);   
    plimit("%24d",INT16_MIN);     plimit("%24d",INT16_MAX);  
    plimit("%24d",INT32_MIN);     plimit("%24d",INT32_MAX);  
    plimit("%24lld",INT64_MIN);   plimit("%24lld",INT64_MAX);
                
    BcArithmetic_error_handler=test_error_handler;

    int test_success_count=0;
    int test_failure_count=0;

#define test_success(format,type,a,b,name,op,c)                         \
    do{                                                                 \
        if(!setjmp(test_jump)){                                         \
            type va=a;                                                  \
            type vb=b;                                                  \
            type vc=name(va,vb);                                        \
            printf("%s "format" %s "format" = "format"\n",              \
                   #type,va,#op,vb,vc);                                 \
            assert(vc==c);                                              \
            test_success_count++;}                                      \
        else{                                                           \
            fprintf(stderr,"FAILURE: detected a %s error for %s ",      \
                    BcArithmetic_error_label[test_error],               \
                    #name);                                             \
            BcArithmetic_argument args[2];                              \
            args[0].typetag=BcArithmetic_typetag_##type;                \
            args[0].value.v_##type=a;                                   \
            args[1].typetag=BcArithmetic_typetag_##type;                \
            args[1].value.v_##type=b;                                   \
            fprint_argument(stderr,&args[0]);                           \
            fprintf(stderr,", ");                                       \
            fprint_argument(stderr,&args[1]);                           \
            fprintf(stderr,"\n");                                       \
            test_failure_count++;}                                      \
    }while(0)

#define test_error(format,type,a,b,name,op,error)                       \
    do{                                                                 \
    if(!setjmp(test_jump)){                                             \
    type va=a;                                                          \
    type vb=b;                                                          \
    type vc=name(va,vb);                                                \
    printf("FAILURE: error not detected\n");                            \
    printf("%s "format" %s "format" = "format"\n",#type,va,#op,vb,vc);  \
    test_failure_count++;}                                              \
    else{                                                               \
    int success=(test_error==BcArithmetic_error_##error);               \
    fprintf(stderr,"Detected %s a %s error for %s ",                    \
            success?"correctly":"erroneous",                            \
            BcArithmetic_error_label[test_error],                       \
            #name);                                                     \
    if(!success){                                                       \
    fprintf(stderr,"Expected a %s\n",                                   \
            BcArithmetic_error_label[BcArithmetic_error_##error]);}     \
    BcArithmetic_argument args[2];                                      \
    args[0].typetag=BcArithmetic_typetag_##type;                        \
    args[0].value.v_##type=a;                                           \
    args[1].typetag=BcArithmetic_typetag_##type;                        \
    args[1].value.v_##type=b;                                           \
    fprint_argument(stderr,&args[0]);                                   \
    fprintf(stderr,", ");                                               \
    fprint_argument(stderr,&args[1]);                                   \
    fprintf(stderr,"\n");                                               \
    if(success){                                                        \
    test_success_count++;}                                              \
    else{                                                               \
    test_failure_count++;}}                                             \
}while(0)

    test_success("%hu",uint16_t,0,0,add,+,0);
    test_success("%hu",uint16_t,0,1,add,+,1);
    test_success("%hu",uint16_t,1,0,add,+,1);
    test_success("%hu",uint16_t,0,UINT16_MAX,add,+,UINT16_MAX);
    test_success("%hu",uint16_t,UINT16_MAX,0,add,+,UINT16_MAX);
    test_success("%hu",uint16_t,1,(UINT16_MAX-1),add,+,UINT16_MAX);
    test_success("%hu",uint16_t,(UINT16_MAX-1),1,add,+,UINT16_MAX);
    test_error("%hu",uint16_t,1,UINT16_MAX,add,+,overflow);
    test_error("%hu",uint16_t,UINT16_MAX,1,add,+,overflow);
    test_error("%hu",uint16_t,UINT16_MAX,UINT16_MAX,add,+,overflow);

    test_success("%hu",uint16_t, 2000,30000,add,+,32000);
    test_success("%hu",uint16_t,30000, 2000,add,+,32000);
    test_success("%hu",uint16_t,30000,20000,sub,-,10000);
    test_error  ("%hu",uint16_t,20000,30000,sub,-,underflow);

    test_success("%hd",int16_t, 2000,30000,add,+,32000);
    test_success("%hd",int16_t,30000, 2000,add,+,32000);
    test_success("%hd",int16_t,30000,20000,sub,-,10000);
    test_success("%hd",int16_t,20000,30000,sub,-,-10000);
    test_success("%hd",int16_t,-32767,-1,mul,*,32767);
    test_error  ("%hd",int16_t,-32768,-1,mul,*,overflow);

    printf("Test success count = %5d\n",test_success_count);
    printf("Test failure count = %5d\n",test_failure_count);
    return 0;}
