#include <stdlib.h>
#include <stdnoreturn.h>

#if defined(__GNUC__) || defined(__gnuc__) || defined(__clang__)
#  define __initfunc__ __attribute__((section (".text.init")))
#  define __noreturn__ __attribute__((__noreturn__))
#  define __unused__   __attribute__((__unused__))
#else
#  define __initfunc__ 
#  define __noreturn__ noreturn
#  define __unused__   
#endif


void __noreturn__ foo1(void)
{
    exit(0);
}
void noreturn foo2(void)
{
    exit(0);
}

typedef void __noreturn__ (*uu_noreturn_fp)(void);

#if 0
/*
Both gcc and clang reject _Noreturn on function pointers.
*/
typedef void noreturn (*noreturn_fp)(void);
#endif

int main() {
    __unused__ int voo; 
    uu_noreturn_fp foo3 = foo1; /* both declared with __noreturn__ */
#if 0
    noreturn_fp foo4 = foo2; /* both declared with noreturn */
#endif
#if 0
    /* 
clang -Wall -Werror -std=c11 -o uu_noreturn-clang uu_noreturn.c 
uu_noreturn.c:46:20: error: incompatible function pointer types initializing 'uu_noreturn_fp' (aka 'void (*)(void) __attribute__((noreturn))') with an expression of type 'void (void)' [-Werror,-Wincompatible-function-pointer-types]
    uu_noreturn_fp foo5 = foo2;
                   ^      ~~~~
1 error generated.
    */
    uu_noreturn_fp foo5 = foo2; /* one declared with __noreturn__ the other with noreturn */
#endif
    foo1();
    foo2();
    foo3();
    /* foo4(); */
    /* foo5(); */
    return 0;
}
