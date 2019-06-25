#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sysexits.h>
#include <errno.h>
#include <locale.h>

const int buffer_size=4096;

void wcs_reverse(wchar_t buffer[],size_t size){
    if(size>0){
        size_t i=0;
        size_t j=size-1;
        while(i<j){
            wchar_t temp=buffer[i];
            buffer[i]=buffer[j];
            buffer[j]=temp;
            ++i;
            --j;
        }
    }
}


void error(int exitCode,const char* formatControl,...){
    va_list args;
    fprintf(stderr,"ERROR: ");
    va_start(args,formatControl);
    vfprintf(stderr,formatControl,args);
    va_end(args);
    fprintf(stderr,"\n");
    exit((exitCode==0)?EX_SOFTWARE:exitCode);
}


void reverse_lines(FILE* input,FILE* output){
    int     lino=0;
    char    byte_buffer[buffer_size];
    wchar_t character_buffer[buffer_size];
    clearerr(input);
    while(fgets(byte_buffer,buffer_size,input)){
        ++lino;
        size_t byte_length=strlen(byte_buffer);
        if(byte_length>0){
            if(byte_buffer[byte_length-1]=='\n'){
                --byte_length;
                byte_buffer[byte_length]=0;
            }else{
                // Line was too long.
                error(EX_DATAERR,"Line %d is too long.",lino);
            }
        }
        ssize_t character_length=mbstowcs(character_buffer,byte_buffer,buffer_size);
        if(character_length<0){
            error(EX_DATAERR,"Found invalid code sequence on line %d\n",lino);
        }
        wcs_reverse(character_buffer,character_length);
        character_buffer[character_length]=0;
        byte_length=wcstombs(byte_buffer,character_buffer,buffer_size-2);
        byte_buffer[byte_length]='\n';
        ++byte_length;
        byte_buffer[byte_length]=0;
        errno=0;
        int result=fputs(byte_buffer,output);
        if(result<0){
            error(EX_OSERR,strerror(errno));
        }
        clearerr(input);
    }
    int result=ferror(input);
    if(result!=0){
        error(EX_IOERR,"Error while reading input.");
    }
}
    

int main(const int argc,const char* argv[]){
    setlocale(LC_ALL,getenv("LC_ALL"));
    setlocale(LC_CTYPE,getenv("LC_CTYPE"));
    reverse_lines(stdin,stdout);
    return 0;
}
