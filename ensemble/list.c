#include <list.h>
#include <util.h>
#include <stdlib.h>
#include <stdio.h>

list_t* make_empty_list(void){
    return NIL; }

list_t* cons(int element,list_t* rest){
    list_t* new=check_memory(malloc(sizeof(*new)));
    new->element=element;
    new->next=rest;
    return new;}

int car(list_t* list){
    return list
            ?list->element
            :0;}

list_t* cdr(list_t* list){
    return list
            ?list->next
            :NIL;}

void push(int element,list_t** list){
    (*list)=cons(element,*list);}

list_t* nreverse(list_t* list){
    list_t* reversed=NIL;
    while(list){
        list_t* current=list;
        list=cdr(list);
        current->next=reversed;
        reversed=current;}
    return reversed;}

int length(list_t* list){
    int count=0;
    while(list){
        count++;
        list=cdr(list);}
    return count;}

void list_print(list_t* list){
    if(NIL==list){
        printf("NIL");
    }else{
        printf("(");
        const char* sep="";
        while(list){
            printf("%s%d",sep,car(list));
            sep=",";
            list=cdr(list);}
        printf(")");}}
        
