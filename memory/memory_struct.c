//https://termbin.com/7a55

#include <stdlib.h>
#include <stdio.h>


typedef struct {
    unsigned next;
    // …
} memory_node;


#ifdef DEBUG
#define MEMORY_SIZE 0x100
#else
#define MEMORY_SIZE 0x1000000
#endif

memory_node memory[MEMORY_SIZE];
unsigned freelist_head;
// memory[0] is unused, since 0 is the null pointer.

void memory_initialize(){
    freelist_head=0;
    for(unsigned address=MEMORY_SIZE-1;0<address;address--){
        memory[address].next=freelist_head
                freelist_head=address;}}

unsigned address_alloc(){
    if(freelist_head==0){
        return NULL;}
    unsigned address=freelist_head;
    freelist_head=memory[freelist_head].next;
    return address;}

memory_node* memory_alloc(){
    unsigned address=address_alloc();
    if(address==0){
        return NULL;}
    return &memory[address];}

void address_free(unsigned newfree){
    memory[newfree].next=freelist_head;
    freelist_head=newfree;}

void memory_free(memory_node* pointer){
    if(NULL!=pointer){
        address_free(pointer-memory);}}



