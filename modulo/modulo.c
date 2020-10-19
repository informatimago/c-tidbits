#include <stdio.h>
#define show(label,x) printf("%s) %-12s = %d\n",#label,#x,x)
int main(){
    
    show(a,8 % 5);
    show(b,-8 % 5);
    show(c,8 % -5);
    show(d,-8 % -5);

    return 0;}

