#include "buffer.h"
#include <string.h>
#include <stdio.h>

static _Noreturn void error_handler(const char* message){
    fprintf(stderr,"ERROR: %s\n",message);
    exit(1);
    /* or create an error object and longjmp to a handler! */}

buffer_error_handler_pr buffer_error_handler=error_handler;

typedef struct buffer {
    byte* data;
    size_t size;
    size_t allocated_size;
    bool allocated_data;
} buffer;

void* checked_malloc(size_t size){
    void* data=malloc(size);
    if(data==NULL){
        buffer_error_handler("Out of Memory");}
    return data;}

void* check_null(void* pointer){
    if(pointer==NULL){
        buffer_error_handler("NULL pointer");}
    return pointer;}

buffer* buffer_alloc(size_t size){
    buffer* buffer=checked_malloc(sizeof(*buffer));
    buffer->allocated_data=true;
    buffer->allocated_size=size;
    buffer->size=size;
    buffer->data=checked_malloc(buffer->allocated_size);
    return buffer;}

buffer* buffer_from_c_buffer_copy(void* data,size_t size){
    buffer* buffer=buffer_alloc(size);
    memcpy(buffer->data,data,size);
    return buffer;}

buffer* buffer_from_c_buffer_no_copy(void* data,size_t size){
    buffer* buffer=checked_malloc(sizeof(*buffer));
    buffer->allocated_data=false;
    buffer->allocated_size=size;
    buffer->size=size;
    buffer->data=data;
    return buffer;}

void buffer_free(buffer* buffer){
    check_null(buffer);
    if(buffer->allocated_data){
        free(buffer->data);}
    memset(buffer,0,sizeof(*buffer));
    free(buffer);}

byte buffer_get_byte(buffer* buffer,size_t index){
    check_null(buffer);
    if((0<=index)&&(index<buffer->size)){
        return buffer->data[index];}
    else{
        buffer_error_handler("Index Out of Range");}}

void buffer_set_byte(buffer* buffer,size_t index,byte byte){
    check_null(buffer);
    if((0<=index)&&(index<buffer->size)){
        buffer->data[index]=byte;}
    else{
        buffer_error_handler("Index Out of Range");}}

size_t buffer_get_size(buffer* buffer){
    check_null(buffer);
    return buffer->size;}

void buffer_set_size(buffer* buffer,size_t newsize){
    check_null(buffer);
    if((0<=newsize)&&(newsize<=buffer->allocated_size)){
        buffer->size=newsize;}
    else{
        buffer_error_handler("Size Out of Range");}}

void buffer_copy(buffer* destination, const buffer* source){
    check_null(destination);
    check_null(source);
    if(source->size<=destination->allocated_size){
        destination->size=source->size;
        memcpy(destination->data,source->data,destination->size);}
    else{
        buffer_error_handler("Buffer size overflow")}}
