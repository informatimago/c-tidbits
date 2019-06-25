#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

void fill(char* string,int size,char fill){
    for(int i=0;i<size;i++){
        string[i]=fill;
    }
    string[size]=0;
}

void diamond(FILE* out,int size){
    char stars[size*2+2];
    fill(stars,sizeof(stars)-1,'*');
    for(int i=0;i<(size-1)*2+1;i++){       //             i     = [ 0      … size-2   size-1   size     … (size-1)*2 ]
        int j=(size-1)-abs(i-(size-1));    //             j     = [ 0      … size-2   size-1   size-2   … 0          ]
        int w=size+j;                      //             w     = [ size   … 2*size-2 2*size-1 2*size-2 … size       ] 
        char* n=stars+(size-j)*2;          // strlen(n) = j*2+1 = [ 1      … 2*size-2 2*size-1 2*size-2 … 1          ]
        fprintf(out,"%*s\n",w,n);
    }
}

int main(int argc,char* argv[]){
    if(argc<=1){
        fprintf(stderr,"Missing size argument.\n");
        return(EX_USAGE);
    }
    int size=0;
    int r=sscanf(argv[1],"%d",&size);
    if((r!=1)||(size<1)){
        fprintf(stderr,"Size argument must be a positive integer.\n");
        return(EX_USAGE);
    }
    diamond(stdout,size);
    return EX_OK;
}
