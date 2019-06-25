
#include <limits.h>

unsigned int uabsi(int n){
    // Only one of two representations are possible for signed
    // integers as per n1124: 2-complement or 1-complement.
    // 1-complement <=>  -INT_MAX == INT_MIN
    // 2-complement <=>  -INT_MAX != INT_MIN
#if -INT_MAX != INT_MIN    
    if(n==INT_MIN){
        return (unsigned int)(-(INT_MIN+1))+1;
    }else
#endif  
    if(n<0){
        return (unsigned int)(-n);
    }else{
        return (unsigned int)n;
    }
}
