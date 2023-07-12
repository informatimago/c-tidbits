#ifndef timeout_h
#define timeout_h

#include "lambda.h"


extern void (FUN _timeout_trampoline_body)(void);
void _timeout_trampoline(void);

#define TIMEOUT_TIMEOUT   33
#define TIMEOUT_COMPLETED 42
int schedule_with_timeout(void (* func)(void), int delay_in_seconds);


#define WITH_TIMEOUT(seconds)                                           \
    do{                                                                 \
    int _timeout_seconds=seconds;                                       \
    FLET(void,_timeout_function,(void))

#define WHEN_TIMEOUT                                                        \
    ;                                                                       \
    _timeout_trampoline_body = _timeout_function;                           \
    switch(schedule_with_timeout(_timeout_trampoline, _timeout_seconds)){   \
    case TIMEOUT_TIMEOUT:

#define WHEN_EARLY_COMPLETION                                           \
    break;                                                              \
    default:

#define END_TIMEOUT                                                     \
    }}while(0)

#endif
