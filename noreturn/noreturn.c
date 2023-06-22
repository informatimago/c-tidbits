#include <stdlib.h>

#if defined(__GNUC__) || defined(__clang__)
  #define HYP_FUNCTION_ATTR(a)    __attribute__((a))
#define HYP_FUNCTION_ATTR2(a,b)    __attribute__((a ## b))
#else
  #define HYP_FUNCTION_ATTR(a)
  #define HYP_FUNCTION_ATTR2(a)
#endif

#undef noreturn
#define __STDNORETURN_H
#define __initfunc__ HYP_FUNCTION_ATTR(section (".text.init"))
#define __unused__ HYP_FUNCTION_ATTR(unused)
#define NORETURN_FP HYP_FUNCTION_ATTR(__noreturn__)
#define NORETURN HYP_FUNCTION_ATTR(__noreturn__)
#define noreturn HYP_FUNCTION_ATTR(__noreturn__)

void NORETURN foo1(void)
{
    exit(0);
}
void noreturn foo2(void)
{
    exit(0);
}

typedef void NORETURN_FP (*noreturn_fp)(void);


int main() {
    noreturn_fp foo3 = foo2;
    foo1();
    foo3();
    return 0;
}
