#include <stdio.h>

int main(int argc,char* argv[]){
    const char* sep="";
    for(int i=1;i<argc;i++){
        printf("%s%s",sep,argv[i]);
        sep=" ";}
    printf("\n");
    fflush(stdout);
    return 0;}
