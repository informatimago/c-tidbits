#ifndef buffer_h
#define buffer_h

#include <stdlib.h>

typedef void (*buffer_error_pr)(const char* message);
buffer_error_pr buffer_error_handler;
typedef unsigned char byte;
typedef struct buffer buffer;
buffer* buffer_alloc(size_t size);
buffer* buffer_from_c_buffer_copy(void* data,size_t size);
buffer* buffer_from_c_buffer_no_copy(void* data,size_t size);
void buffer_free(buffer* buffer);
byte buffer_get_byte(buffer* buffer,size_t index);
void buffer_set_byte(buffer* buffer,size_t index,byte byte);
size_t buffer_get_size(buffer* buffer);
void buffer_set_size(buffer* buffer,size_t newsize);
void buffer_copy(buffer* destination, const buffer* source);

#endif
