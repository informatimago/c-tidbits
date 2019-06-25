#ifndef list_h
#define list_h


typedef struct list_t {
    int element;
    struct list_t* next;
} list_t;

#define NIL ((void*)0)

list_t* make_empty_list(void);
list_t* cons(int element,list_t* rest);
int car(list_t* list);
list_t* cdr(list_t* list);
void push(int element,list_t** list);
list_t* nreverse(list_t* list);
int length(list_t* list);
void list_print(list_t* list);

#endif
