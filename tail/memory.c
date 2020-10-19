#include <stdlib.h>
#include <stdio.h>

/*
Let's implement a naive malloc/free:
the memory is made of blocks. Each block has a rounded 32-bit block size, followed by that number of bytes.
free blocks have a (int) pointer to the next free block after the block size. 
(therefore blocks of size 0 are rounded to 4).
To simplify freellist management, we always keep a small freeblock as head of the list.
*/

#define MEMORY_WORDSIZE ((unsigned)4)

#ifdef DEBUG
#define MEMORY_SIZE 0x100
#else
#define MEMORY_SIZE 0x1000000
#endif
unsigned char memory[MEMORY_SIZE];
unsigned freelist_head;

void store(unsigned address,unsigned value){
    memory[address]=0xff&(value>>24);
    memory[address+1]=0xff&(value>>16);
    memory[address+2]=0xff&(value>>8);
    memory[address+3]=0xff&(value);
#ifdef DEBUG_STORE
    printf("store %08x %08x\n",address,value);
    printf("      %02x %02x %02x %02x\n",memory[address],memory[address+1],memory[address+2],memory[address+3]);
#endif
}

unsigned load(unsigned address){
#ifdef DEBUG_STORE
    printf("load %08x -> %08x\n",address, ((((unsigned)(memory[address]))<<24)
                                           |(((unsigned)(memory[address+1]))<<16)
                                           |(((unsigned)(memory[address+2]))<<8)
                                           |((unsigned)(memory[address+3]))));
#endif
    return ((((unsigned)(memory[address]))<<24)
            |(((unsigned)(memory[address+1]))<<16)
            |(((unsigned)(memory[address+2]))<<8)
            |((unsigned)(memory[address+3])));}

void memory_initialize(){
    freelist_head=MEMORY_WORDSIZE;
    unsigned freelist=3*MEMORY_WORDSIZE; // 2 for the head, 1 for the freelist block size.
    store(freelist_head-MEMORY_WORDSIZE,MEMORY_WORDSIZE);
    store(freelist_head,freelist);
    store(freelist-MEMORY_WORDSIZE,MEMORY_SIZE-3*MEMORY_WORDSIZE);
    store(freelist,0);}

unsigned memory_block_size(unsigned freeblock){
    return load(freeblock-MEMORY_WORDSIZE);}
// The size of the block is actually MEMORY_WORDSIZE+memory_block_size(block), for the size stored before the block.
// The minimum size we can cut out of a freeblock is 2*MEMORY_WORDSIZE.

unsigned memory_block_next(unsigned freeblock){
    return load(freeblock);}

unsigned memory_round_up(size_t size){
    return (size<=0)
            ?MEMORY_WORDSIZE
            :(unsigned)(1+((size-1)/MEMORY_WORDSIZE))*MEMORY_WORDSIZE;}

unsigned search_best_fit(unsigned freelist,unsigned blocksize){
    unsigned minimum_free_size=2*MEMORY_WORDSIZE+blocksize;
    unsigned previous_bestfit=0;
    unsigned bestfit=0;
    unsigned bestfit_size=0;
    unsigned freeblock;
    while(0!=(freeblock=memory_block_next(freelist))){
        unsigned freeblock_size=memory_block_size(freeblock);
        if(minimum_free_size<=freeblock_size){
            if((bestfit_size==0)||(freeblock_size<bestfit_size)){
                previous_bestfit=freelist;
                bestfit=freeblock;
                bestfit_size=freeblock_size;}}
        freelist=freeblock;}
    // remove the bestfit from the list:
    store(previous_bestfit,memory_block_next(bestfit)); 
    return bestfit;}

void memory_free_list_add(unsigned newfree){
    store(newfree,memory_block_next(freelist_head));
    store(freelist_head,newfree);}

void* malloc(size_t size){
    unsigned blocksize=memory_round_up(size);
    unsigned freeblock=search_best_fit(freelist_head,size);
    if(freeblock==0){
        return NULL;}
    unsigned freeblock_size=memory_block_size(freeblock);
    if(blocksize<freeblock_size){
        // let's cut:
        unsigned freeblock_end=freeblock+freeblock_size;
        unsigned remainfree=freeblock+blocksize+MEMORY_WORDSIZE;
        unsigned remainfree_size=freeblock_end-remainfree;
        store(freeblock-MEMORY_WORDSIZE,blocksize);
        store(remainfree-MEMORY_WORDSIZE,remainfree_size);
        memory_free_list_add(remainfree);}
    return &(memory[freeblock]);}

void free(void* pointer){
    if(NULL!=pointer){
        unsigned address=(unsigned)((unsigned char*)pointer-&memory[0]);
        if(address<MEMORY_SIZE){
            memory_free_list_add(address);}}}

typedef enum {
    memory_null             = 0x00,
    memory_unaligned        = 0x01,
    memory_invalid          = 0x10, // never with unaligned.
    memory_free_size        = 0x20, 
    memory_free_block       = 0x30, 
    memory_free_next        = 0x40, 
    memory_allocated_block  = 0xA0,
    memory_allocated_size   = 0xB0, 
} memory_address_class;

unsigned memory_address_in_free_block(unsigned address){
    // Note address==0 is in header, but we consider it as NULL.
    unsigned current=freelist_head;
    while((current!=0)
          &&((address<current-MEMORY_WORDSIZE)
             ||((current+memory_block_size(current))<=address))){
        current=memory_block_next(current);}
    return current;}

memory_address_class memory_classify_address(unsigned address){
    if(address==0){
        return memory_null;}
    if(MEMORY_SIZE<=address){
        return memory_invalid;}
    unsigned freeblock=memory_address_in_free_block(address);
    if(freeblock){
        if(address==freeblock-MEMORY_WORDSIZE){
            return memory_free_size;}
        else if(address<freeblock){
            return memory_free_size|memory_unaligned;}
        else if(address==freeblock){
            return memory_free_next;}
        else if(address<freeblock+MEMORY_WORDSIZE){
            return memory_free_next|memory_unaligned;}
        else if(address==freeblock+MEMORY_WORDSIZE){
            return memory_free_block;}
        else{
            return memory_free_block|memory_unaligned;}}
    unsigned block=4;
    while((block<MEMORY_SIZE)
          &&((address<block-MEMORY_WORDSIZE)
             ||(block+memory_block_size(block)<=address))){
        block=block+memory_block_size(block)+MEMORY_WORDSIZE;}
    // cannot be invalid, since we tested before the loop.
    if(address==block-MEMORY_WORDSIZE){
        return memory_allocated_size;}
    else if(address<block){
        return memory_allocated_size|memory_unaligned;}
    else if(address==block){
        return memory_allocated_block;}
    else{
        return memory_allocated_block|memory_unaligned;}}

void memory_dump(FILE* out){
    unsigned block=4;
    while(block<MEMORY_SIZE){
        memory_address_class class=memory_classify_address(block);
        switch(class){
          case memory_free_next:
              fprintf(out,"%08x: size: %08x   next: %08x  free\n",
                      block,memory_block_size(block),memory_block_next(block));
              break;
          case memory_allocated_block:
              fprintf(out,"%08x: size: %08x   next: %08x  allocated\n",
                      block,memory_block_size(block),block+memory_block_size(block));
              break;
          default:
              fprintf(out,"%08x: %02x\n",
                      block,class);}
        block=block+memory_block_size(block)+MEMORY_WORDSIZE;}}

void test_round_up(){
    for(unsigned int i=0;i<17;i++){
        printf("%u -> %u\n",i,memory_round_up(i));}}

void test_malloc_free(){
    int count=6;
    void* blocks[count];
    printf("// Initialize\n");
    memory_initialize();
    printf("// Before:\n");
    memory_dump(stdout);
    for (int i=0;i<count;i++){
        blocks[i]=malloc(10*i);}
    printf("// After malloc's:\n");
    memory_dump(stdout);
    for (int i=0;i<count;i+=2){
        free(blocks[i]);
        blocks[i]=NULL;}
    printf("// After free's:\n");
    memory_dump(stdout);
    for (int i=0;i<count;i+=2){
        blocks[i]=malloc(10*i+5);}
    printf("// After malloc's:\n");
    memory_dump(stdout);}

/*
-*- mode: compilation; default-directory: "~/src/c/tail/" -*-
Compilation started at Mon Sep  7 18:37:20

SRC="/Users/pjb/src/c/tail/memory.c" ; EXE="memory" ; clang -DDEBUG -I. -L. -g3 -ggdb3 -o ${EXE} ${SRC} &&  ./${EXE} && echo status = $?
// Initialize
// Before:
00000004: size: 00000004   next: 0000000c  free
0000000c: size: 000000f4   next: 00000000  free
// After malloc's:
00000004: size: 00000004   next: 000000c4  free
0000000c: size: 00000004   next: 00000010  allocated
00000014: size: 0000000c   next: 00000020  allocated
00000024: size: 00000014   next: 00000038  allocated
0000003c: size: 00000020   next: 0000005c  allocated
00000060: size: 00000028   next: 00000088  allocated
0000008c: size: 00000034   next: 000000c0  allocated
000000c4: size: 0000003c   next: 00000000  free
// After free's:
00000004: size: 00000004   next: 00000060  free
0000000c: size: 00000004   next: 000000c4  free
00000014: size: 0000000c   next: 00000020  allocated
00000024: size: 00000014   next: 0000000c  free
0000003c: size: 00000020   next: 0000005c  allocated
00000060: size: 00000028   next: 00000024  free
0000008c: size: 00000034   next: 000000c0  allocated
000000c4: size: 0000003c   next: 00000000  free
// After malloc's:
00000004: size: 00000004   next: 000000f8  free
0000000c: size: 00000004   next: 00000000  free
00000014: size: 0000000c   next: 00000020  allocated
00000024: size: 00000008   next: 0000002c  allocated
00000030: size: 00000008   next: 0000000c  free
0000003c: size: 00000020   next: 0000005c  allocated
00000060: size: 0000001c   next: 0000007c  allocated
00000080: size: 00000008   next: 00000030  free
0000008c: size: 00000034   next: 000000c0  allocated
000000c4: size: 00000030   next: 000000f4  allocated
000000f8: size: 00000008   next: 00000080  free
status = 0

Compilation finished at Mon Sep  7 18:37:20

*/
int main(){
    test_malloc_free();    
    return 0;}


