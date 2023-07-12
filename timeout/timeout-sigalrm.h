#ifndef timeout_h
#define timeout_h

#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

extern int timeout_timedout;
extern jmp_buf timeout_setjmp_buffer;
void timeout_signal_handler(int);

#define TIMEOUT_TIMEOUT   33
#define TIMEOUT_COMPLETED 42
int schedule_with_timeout(void (* func)(void), int delay_in_seconds);


#define WITH_TIMEOUT(seconds)                                           \
    do{                                                                 \
    timeout_timedout = 0;                                               \
    signal(SIGALRM, timeout_signal_handler);                            \
    alarm(seconds);                                                     \
    if(0==setjmp(timeout_setjmp_buffer))

#define WHEN_TIMEOUT                                                    \
    signal(SIGALRM, SIG_IGN);                                           \
    if(timeout_timedout)                                                \
        
#define WHEN_EARLY_COMPLETION                                           \
    else

#define END_TIMEOUT                                                     \
    }while(0)

#endif
