#include <stdio.h>

int f(long c,...)
{
    long* p=(&c)-1;
    long r=0;
    while(0<c--)
    {
        printf("p = %p *p = %ld\n", p, *p);
        r +=(*p -- );
    }
    return r;
}

int g(long i,  long j, long k, long l,  long m)
{
    long* p=(&i);
    long r=0;
    int c = 5;
    while(0<c--)
    {
        printf("p = %p *p = %ld\n", p, *p);
        r +=(*p -- );
    }
    printf("p = %p *p = %ld\n", &i, i);
    printf("p = %p *p = %ld\n", &j, j);
    printf("p = %p *p = %ld\n", &k, k);
    printf("p = %p *p = %ld\n", &l, l);
    printf("p = %p *p = %ld\n", &m, m);
    return r;
}


int main()
{
    printf("sum = %d\n", f(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    printf("sum = %d\n", g(1, 2, 3, 4, 5));
    return 0;
}
