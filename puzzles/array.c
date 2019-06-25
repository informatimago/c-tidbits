#include<stdio.h>

#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
int array[] = {23,34,12,17,204,99,16};

int main()
{
    int d=-1;

    printf("TOT=%lu\nTOT-2=%lu\nd <= (TOTAL_ELEMENTS-2) = %d\n",
           TOTAL_ELEMENTS,(TOTAL_ELEMENTS-2),
           d <= (int)(TOTAL_ELEMENTS-2));

    for(d=-1;d <= (int)(TOTAL_ELEMENTS-2);d++){
        printf("d=%d TOT-2=%lu\n",d,(TOTAL_ELEMENTS-2));
        printf("%d\n",array[d+1]);
    }

    return 0;
}
