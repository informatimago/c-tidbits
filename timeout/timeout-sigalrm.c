#include "timeout-sigalrm.h"

int timeout_timedout;
jmp_buf timeout_setjmp_buffer;

void timeout_signal_handler(int)
{
    timeout_timedout = 1;
    longjmp(timeout_setjmp_buffer,1);
}


int schedule_with_timeout(void (* func)(void), int delay_in_seconds)
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
