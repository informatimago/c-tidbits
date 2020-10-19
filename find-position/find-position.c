#include <stdio.h>


typedef struct {
    size_t position;
    union {
        struct {
            const void* array;
            size_t element_size;
            size_t nelements;
        } array;
        struct {
            FILE* file;
        } file;
    } impl;
} sequence;

sequence* open_array(const void* array,size_t element_size,size_t nelements){
}

int main(){
    return 0;}
