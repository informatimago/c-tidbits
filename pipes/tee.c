#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "tee.h"


void copy_streams(int input,int outputs_count,int* outputs,int exit_at_first_close){
}

typedef struct {
    int input;
    int outputs_count;
    int* outputs;
    int exit_at_first_close;
} copy_streams_closure;

void* start_routine(void* data){
    copy_streams_closure* that=data;
    copy_streams(that->input,that->outputs_count,that->outputs,that->exit_at_first_close);
    free(data);
    return NULL;}

int tee(int input,int outputs_count,int* outputs,int flags){
    pid_t pid=0;
    if(flags&tee_thread){
        pthread_t thread;
        pthread_attr_t attr;
        copy_streams_closure* closure=malloc(sizeof(*closure));
        closure->input=input;
        closure->outputs_count=outputs_count;
        closure->outputs=outputs;
        closure->exit_at_first_close=flags&tee_first;
        if(0==pthread_create(&thread,&attr,start_routine,closure)){
            return getpid();}
        else{
            return -1;}}
    else{
        pid=fork();
        if(pid!=0){
            return pid;}
        copy_streams(input,outputs_count,outputs,flags&tee_first);}
    return 0;}


int main(){
    return 0;}
