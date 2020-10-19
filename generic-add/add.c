#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#undef WITH_FIX32

void type_error_arguments(const char* fname,const char* type){
    fprintf(stderr,"type error: %s() got %s, expected one of float, uint32_t, int32_t, fix32_t.\n",
            fname,type);
    exit(1);}

#define TYPE_ERROR_ARGUMENTS(fname,type)  type_error_arguments(fname,#type)
#ifdef WITH_FIX32
#define add(a, b) _Generic(a,                                         \
                           int32_t:  add_int32_t(a,b),                  \
                           uint32_t: add_uint32_t(a,b),                 \
                           float:    add_float(a,b),                    \
                           fix32_t:  add_fix32_t(a,b),                  \
                           default:  (TYPE_ERROR_ARGUMENTS("add",typeof(a)),(number){type_int32_t,.value.i=0}))
#else
#define add(a, b) _Generic(a,                                         \
                           int32_t:  add_int32_t(a,b),                  \
                           uint32_t: add_uint32_t(a,b),                 \
                           float:    add_float(a,b),                    \
                           default:  (TYPE_ERROR_ARGUMENTS("add",typeof(a)),(number){type_int32_t,.value.i=0}))
#endif

typedef struct fix32_t {
    int32_t data;
} fix32_t;

const char* typetag_label[]={"type_float","type_int32_t","type_uint32_t","type_fix32_t" };

typedef struct {
    enum { type_float,type_int32_t,type_uint32_t,type_fix32_t } typetag;
    union {
        float f;
        int32_t i;
        uint32_t u;
        fix32_t x;
    } value;
} number;


number add_float(float a,float b){
    return (number){type_float,.value.f=a+b};}

number add_uint32_t(uint32_t a,uint32_t b){
    return (number){type_uint32_t,.value.u=a+b};}

number add_int32_t(int32_t a,int32_t b){
    return (number){type_int32_t,.value.i=a+b};}

fix32_t fix32_from_int(uint8_t decimal_places, int int_value) {
    return (fix32_t) { .data = int_value << decimal_places};}

fix32_t fix32_add(fix32_t a, fix32_t b) {
    return (fix32_t) { .data = a.data + b.data};}

number add_fix32_t(fix32_t a,fix32_t b){
    return (number){type_fix32_t,.value.x=fix32_add(a,b)};}

uint32_t number_uint32_t(number n){
    if(n.typetag!=type_uint32_t){
        fprintf(stderr,"type error: %s() expected type_uint32_t, got %s",__FUNCTION__,typetag_label[n.typetag]);
        exit(1);}
    return n.value.u;}

int32_t number_int32_t(number n){
    if(n.typetag!=type_int32_t){
        fprintf(stderr,"type error: %s() expected type_int32_t, got %s",__FUNCTION__,typetag_label[n.typetag]);
        exit(1);}
    return n.value.i;}

fix32_t number_fix32_t(number n){
    if(n.typetag!=type_fix32_t){
        fprintf(stderr,"type error: %s() expected type_fix32_t, got %s",__FUNCTION__,typetag_label[n.typetag]);
        exit(1);}
    return n.value.x;}

float number_float(number n){
    if(n.typetag!=type_float){
        fprintf(stderr,"type error: %s() expected type_float, got %s",__FUNCTION__,typetag_label[n.typetag]);
        exit(1);}
    return n.value.f;}

int main() {
    uint8_t c = number_uint32_t(add(-4, 4));
    printf("%d\n", c);
    float    f = number_float(add(4.0, 3.14));
    printf("%f\n", f);

#ifdef WITH_FIX32
    uint8_t decimal_places = 16;
    fix32_t fa = fix32_from_int(decimal_places, 4);
    fix32_t fb = fix32_from_int(decimal_places, 4);
    fix32_t fc = number_fix32_t(add(fa, fb));
    printf("%d\n", (int) fc.data);
#endif
    return 0;}
