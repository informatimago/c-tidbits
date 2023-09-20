#include <stdio.h>
#include <stdarg.h>


#define PANIC(fmt, args...) \
    panic(__FILE__,__LINE__,__FUNCTION__,fmt, ##args) 

void panic(const char* file, int line, const char* func, const char* fmt, ...)
{
    printf("%s:%d: in %s: ",file,line,func);
    va_list ap=va_start(fmt);
    vprintf(fmt,ap);
    va_end(ap);
}



void foo()
{
    PANIC("I don't feel right");
}




int main()
{
    foo();
    return 0;
}

