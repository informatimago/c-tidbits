#include <stdio.h>
#include <unistd.h>
int main(int argc,char* argv[]){
    if(argc>1){
        char* pname=argv[0];
        argv[0]="You're fucked";
        execv(pname,argv);
    }
    printf("argv[0]=%s\n",argv[0]);
    sleep(3600);
    return 0;
}
