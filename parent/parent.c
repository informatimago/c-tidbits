#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t child=0;
    if(0!=(child=fork())){
        // parent
        printf("child= %d\n",child);
        exit(0);}
    sleep(120);
    return 0;}

