#include <stdio.h>

int d[16];
int SATD (void) {
    int satd = 0, dd, k;
    for ((dd=d[k=0],printf("k=%d\n",k)); k<16; (dd=d[++k],printf("k=%d\n",k))) {
        printf("inc\n");
        satd += (dd < 0 ? -dd : dd); }
    return satd;
}
int main(){
    SATD();
    return 0;
}
