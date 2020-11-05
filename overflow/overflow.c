#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef bool (compare_pr*)(int,int,int,compare_pr,compare_pr);

bool product_compare(int a,int b,int n,compare_pr smaller,compare_pr greater){
    /* return whether a*b<n */
    // First, deal with signs. Fall back to positive case,
    // taking into account INT_MIN which is 1 less than -INT_MAX.
    _Static_assert(-(INT_MIN+1)==INT_MAX,"Expected 2-complement.");
    if(a<0){
        if(b<0){
            // a*b>=0, a<0, b<0
            if(n<0){
                return false;}
            else{
                if(a==INT_MIN){
                    if(b==INT_MIN){
                        return true;}
                    else{
                        return product_smaller(-(a+1),-b,n+b);}}
                else{
                    if(b==INT_MIN){
                        return product_smaller(-a,-(b+1),n+a);}
                    else{
                        return product_smaller(-a,-b,n);}}}}
        else{
            // a*b<0, a<0, b>=0
            if(n<0){
                if(a==INT_MIN){
                    return product_greater(-(a+1),b,b-n);}
                else{
                    return product_greater(-a,b,-n);}}
            else{
                return true;}}}
    else{
        if(b<0){
            // a*b<0, a>=0, b<0
            if(n<0){
                if(b==INT_MIN){
                    return product_greater(a,-(b+1),a-n);}
                else{
                    return product_greater(a,-b,-n);}}
            else{
                return true;}}
        else{
            // a*b>=0
            if(n<0){
                return false;}
            else{
                if((a==0)||(b==0)){
                    return 0<n;}
                else{
                    // order so that a>=b
                    if(a<b){
                        return product_smaller(b,a,n);}
                    else{
                        // 0<b<a
                        int c=n/b; // = ⸤n/b⸥
                        if(a<c){
                            return true;}
                        else{
                            /*
                                a*b < n
                                a < n/b
                                a < ⸤n/b⸥ + f(n/b)       
                                a < ⸤n/b⸥ + (n-⸤n/b⸥*b)/b 
                                a - ⸤n/b⸥ < n/b - ⸤n/b⸥ 
                                (a - ⸤n/b⸥)*b < n - ⸤n/b⸥*b
                            */                      
                            return ((a-c)*b)<(n-c*b);}}}}}}}

bool product_smaller(int a,int b,int n){
    
}



void test_product_smaller(){

    assert(!product_smaller(0,0,0));
    assert( product_smaller(0,0,1));

    assert(!product_smaller(-1,-1,-2));
    assert(!product_smaller(-1,-1,-1));
    assert(!product_smaller(-1,-1, 0));
    assert(!product_smaller(-1,-1,+1));
    assert( product_smaller(-1,-1,+2));

    assert(!product_smaller(-1,+1,-2));
    assert(!product_smaller(-1,+1,-1));
    assert( product_smaller(-1,+1, 0));
    assert( product_smaller(-1,+1,+1));

    assert(!product_smaller(+1,-1,-2));
    assert(!product_smaller(+1,-1,-1));
    assert( product_smaller(+1,-1, 0));
    assert( product_smaller(+1,-1,+1));

    assert(!product_smaller(+1,+1,-2));
    assert(!product_smaller(+1,+1,-1));
    assert(!product_smaller(+1,+1, 0));
    assert(!product_smaller(+1,+1,+1));
    assert( product_smaller(+1,+1,+2));

    assert(!product_smaller(+3,+5,-16000));
    assert(!product_smaller(+3,+5,-16));
    assert(!product_smaller(+3,+5,+14));
    assert(!product_smaller(+3,+5,+15));
    assert( product_smaller(+3,+5,+16));

    assert(!product_smaller(+5,+3,-16000));
    assert(!product_smaller(+5,+3,-16));
    assert(!product_smaller(+5,+3,+15));
    assert( product_smaller(+5,+3,+16));
    assert( product_smaller(+5,+3,+16000));

    assert(!product_smaller(INT_MIN,0,0));
    assert( product_smaller(INT_MIN,0,1));

    assert(!product_smaller(INT_MIN,1,INT_MIN));
    assert( product_smaller(INT_MIN,1,INT_MIN+1));
    
}

int main(){
    test_product_smaller();
    return 0;}
