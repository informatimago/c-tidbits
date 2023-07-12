#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "timeout-pthread.h"

/* Function to be executed in the new thread */

void (FUN _timeout_trampoline_body)(void);

void _timeout_trampoline(void){
    _timeout_trampoline_body();
}

static int thread_cancelled;

static void* thread_function(void* arg) {
    int oldstate=0;

    /* Set cancel state, and save old state: */
    int ret = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
    if (0 != ret)
        perror("pthread_setcancelstate");

    /* Call the function provided as a parameter: */
    thread_cancelled = 1;
    {
        void (*func)(void) = arg;
        func();
    }
    thread_cancelled = 0;
    /* Thread finishes before the delay */

    /* Restore old state */
    ret = pthread_setcancelstate(oldstate, NULL);
    if (0 != ret)
        perror("pthread_setcancelstate");

    return NULL;
}

/* Function to schedule the thread and handle cancellation */
int schedule_with_timeout(void (* func)(void), int delay_in_seconds) {
    pthread_t thread;
    int result;

    /* Create the thread */
    result = pthread_create(&thread, NULL, thread_function, (void*) func);
    if (result != 0) {
        perror("pthread_create failed");
        return -1;
    }

    /* Wait for the specified delay */
    sleep(delay_in_seconds);

    /* Cancel the thread if the delay is reached */
    result = pthread_cancel(thread);
    if (result != 0) {
        perror("pthread_cancel failed");
        return -1;
    }

    /* Return a different value if the thread is cancelled */
    if (thread_cancelled) {
        return TIMEOUT_TIMEOUT;
    } else {
        return TIMEOUT_COMPLETED;
    }
}

