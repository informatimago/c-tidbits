#include "timeout.h"
#include <setjmp.h>

     /* We cannot include <signal.h> since that will include*
      * <string.h> and others and unfortunately we have a file named
      * string.h and others, with incompatible declarations.
      * Of course, this will break when the sysroot will have
      * different values for SIGALRM and SIG_IGN.
      */
     typedef void (*sighandler_t)(int);
     sighandler_t
signal(int signum, sighandler_t handler);
#define SIGALRM 14
#define SIG_IGN ((sighandler_t)1)
     /* And same with unistd.h for alarm(): */
       unsigned int alarm(unsigned int seconds);


     static int timeout_timedout;
     static jmp_buf timeout_setjmp_buffer;

     static void
timeout_signal_handler(int sigint)
{
    (void)sigint;
    timeout_timedout = 1;
    longjmp(timeout_setjmp_buffer, 1);
}

     int
timeout_begin(unsigned int seconds)
{
    int res;
    timeout_timedout = 0;
    res = setjmp(timeout_setjmp_buffer);
    if(0 == res){
	signal(SIGALRM, timeout_signal_handler);
	alarm(seconds);
    }
    return res;
}

     int
timeout_end(void)
{
    signal(SIGALRM, SIG_IGN);
    return timeout_timedout;
}

     int
schedule_with_timeout(void (* func)(void), int delay_in_seconds)
{
    WITH_TIMEOUT(delay_in_seconds){
        func();
    }
    WHEN_TIMEOUT{
	/* success */
        return TIMEOUT_TIMEOUT;
    }
    WHEN_EARLY_COMPLETION{
        return TIMEOUT_COMPLETED;
    }
    END_TIMEOUT;
}
