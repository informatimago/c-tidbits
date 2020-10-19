#ifndef print_binary_h
#define print_binary_h
#include <stdio.h>

enum {print_binary_prefix=1};
void fprint_binary(FILE* output,unsigned width,unsigned value,unsigned flag);
void print_binary(unsigned width,unsigned value,unsigned flag);

#endif
