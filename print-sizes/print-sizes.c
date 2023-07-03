#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define print_size(type) printf("sizeof %-20s = %3lu\n", #type, sizeof(type))

int main(void){
    print_size(char);
    print_size(short);
    print_size(int);
    print_size(long);
    print_size(long long);

    print_size(unsigned char);
    print_size(unsigned short);
    print_size(unsigned int);
    print_size(unsigned long);
    print_size(unsigned long long);

    print_size(int8_t);
    print_size(int16_t);
    print_size(int32_t);
    print_size(int64_t);

    print_size(uint8_t);
    print_size(uint16_t);
    print_size(uint32_t);
    print_size(uint64_t);

    print_size(float);
    print_size(double);

    print_size(void*);
    print_size(char*);
    return 0;
}
