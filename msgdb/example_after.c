#include <stdio.h>
#include <stdarg.h>
#include "msg.h"


#define PANIC(fmt, args...) \
    panic(MSGID(__FILE__,__LINE__,__FUNCTION__),fmt, ##args) 

void panic(const char* message_id, const char* fmt, ...)
{
    printf("%s: ",message_id);
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

