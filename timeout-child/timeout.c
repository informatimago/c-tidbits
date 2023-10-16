#include "timeout.h"
#include <setjmp.h>

#undef USE_ALARM /* use alarm() and SIGALRM (conflicts with sleep() and setitimer()) */
#define USE_CHILD /* Use fork(), and signal() with a parameterized signal (eg. SIGUSR2) */


     /* We cannot include <signal.h> since that will include*
      * <string.h> and others and unfortunately we have a file named
      * string.h and others, with incompatible declarations.
      * Of course, this will break when the sysroot will have
      * different values for SIGALRM and SIG_IGN.
      */
     typedef void (*sighandler_t)(int);
     sighandler_t
signal(int signum, sighandler_t handler);
#define SIG_IGN ((sighandler_t)1)
#define SIGALRM 14
#define SIGTERM 15
#define SIGUSR2 31

#ifdef USE_ALARM
#define TIMEOUT_SIGNAL SIGALRM
     /* And same with unistd.h for alarm(): */
       unsigned int alarm(unsigned int seconds);
#endif

#ifdef USE_CHILD
#define TIMEOUT_SIGNAL SIGUSR2
     int fork(void);
     long getpid(void);
     void _exit(int);
     long wait(int *wstatus);
     int kill(long, int);
     unsigned int sleep(unsigned int); /* (3) */
#endif


#ifdef USE_CHILD
     static int timeout_child_pid = 0;
#endif
     static int timeout_timedout = 0;
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
    long parent_pid = getpid();
    timeout_timedout = 0;
    res = setjmp(timeout_setjmp_buffer);
    if(0 == res){
	signal(TIMEOUT_SIGNAL, timeout_signal_handler);
#ifdef USE_ALARM
	alarm(seconds);
#endif
#ifdef USE_CHILD
	timeout_child_pid = fork();
	if(0 == timeout_child_pid){
	    /* child */
	    sleep(seconds);
	    kill(parent_pid, TIMEOUT_SIGNAL);
	    _exit(0);
	}
#endif
    }
    return res;
}

     int
timeout_end(void)
{
    int status;
    /* In case the timeout didn't come from the child, we kill it. */
    if(0 != timeout_child_pid)
	kill(timeout_child_pid, SIGTERM);
    /* In any case we reap the dying child. */
    wait(&status);
    /* Then we ignore the timeout signal. */
    signal(TIMEOUT_SIGNAL, SIG_IGN);
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
