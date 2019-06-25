#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define unused(x) ((void)x)
int irq_processed=0;
void handle_alarm(int signal){
    unused(signal);
    irq_processed=1;}
int main(){
    int count=3;
    struct itimerval timer={ /* interval = */ { 3,0 },
                             /* delay    = */ { 1,0 }};
    signal(SIGALRM,handle_alarm);
    setitimer(ITIMER_REAL,&timer,0);
    while(count>0){
        while(0==irq_processed){
            sleep(1);}
        printf("!");
        fflush(stdout);
        irq_processed=0;
        count--;}
    printf("\n");
    fflush(stdout);
    return 0;}
        
