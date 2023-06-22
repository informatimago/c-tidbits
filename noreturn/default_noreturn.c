#include <stdlib.h>
#include <setjmp.h>


#if 0
/* Rejected by gcc & clang */
void __noreturn foo1(void) {
    exit(0);
}

void noreturn foo2(void) {
    exit(0);
}
#endif

void _Noreturn foo3(void) {
    exit(0);
}


void __attribute__((noreturn)) foo4(void) {
    exit(0);
}

void __attribute__((__noreturn__)) foo5(void) {
    exit(0);
}

int main() {
    typedef void (*goo_t)();
#if 0
    /* Rejected by gcc & clang */
    __noreturn goo_t goo1 = foo1;
    noreturn goo_t goo2 = foo2;
#endif
    /* _Noreturn */  goo_t goo3 = foo3;
    __attribute__((noreturn)) goo_t  goo4 = foo4;
    __attribute__((__noreturn__)) goo_t  goo5 = foo5;

    foo3();
    foo4();
    foo5();
    goo3();
    goo4();
    goo5();
    return 0;
}
