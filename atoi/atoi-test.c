#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
    int i;
    for(i=1;i<argc;i++){
        printf("atoi(\"%s\") -> %d\n",(argv[i]),atoi(argv[i]));
    }
    for(i=1;i<argc;i++){
        char* end;
        end=argv[i]+strlen(argv[i]);
        printf("strtol(\"%s\",0) -> %ld\n",(argv[i]),strtol(argv[i],&end,0));
    }
    return 0;
}
