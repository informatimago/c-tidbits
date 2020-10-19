#include <limits.h>
#include "remove_bits.h"

octet remove_bits(octet source,octet mask){
    octet result=0;
    for(unsigned m=1,bit=1;m<=UCHAR_MAX;m<<=1){
        if(m&mask){
            if(m&source){
                result|=bit;}
            bit<<=1;}}
    return result;}

