#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void* check_pointer(void* pointer){
    if(!pointer){
        fprintf(stderr,"malloc returned NULL\n");
        exit(1);}
    return(pointer);}


typedef char* cstring;

typedef enum { tag_int, tag_cstring } type_tag;
typedef struct {
    type_tag type;
    union {
        int     integer;
        cstring string;
    } value;
} *object;

typedef struct node {
   object element;
   struct node* next; } *cons;


object make_cstring(cstring string){
    object that=check_pointer(malloc(sizeof(*that)));
    that->type=tag_cstring;
    that->value.string=string;
    return(that);}

object make_integer(int value){
    object that=check_pointer(malloc(sizeof(*that)));
    that->type=tag_int;
    that->value.integer=value;
    return(that);}

cons combine(object element,cons next){
     cons that=check_pointer(malloc(sizeof(*that)));
     that->element=element;
     that->next=next;
     return(that);}

object first(cons node){
    return node?node->element:NULL;}

cons next(cons node){
    return(node?node->next:NULL);}

bool empty(cons node){
    return(!node);}

typedef enum {
    tab_periodic,
    tab_list } tab_type;

typedef struct {
    tab_type type;
    union {
        unsigned period;
        cons list;
    } data;
} *tabs;

tabs make_periodic_tabs(unsigned period){
    tabs that=check_pointer(malloc(sizeof(*that)));
    that->type=tab_periodic;
    that->data.period=period;
    return(that);}

tabs make_list_tabs(cons tab_list){
    tabs that=check_pointer(malloc(sizeof(*that)));
    that->type=tab_periodic;
    that->data.list=tab_list;
    return(that);}

void output_with_tabs(cons chunks){
}

/*|
  |  function detab_file(input_file, tabs, output_file):
  |      for each line in input_file:
  |          detab_line(line,tabs,output_file)
  |
  |  function detab_line(line,tabs,output_file):
  |      output_with_tabs(split_on_tab(line,0),tabs,output_file,0)
  |      write_new_line(output_file)
  |
  |  function split_on_tab(line,start):
  |     tabpos=position(tab,line,start)
  |     if tabpos:
  |        combine(subseq(line,start,tabpos),split_on_tab(line,tabpos+1))
  |     else:
  |        combine(subseq(line,start,length(line)),nil)
  |
  |  function output_with_tabs(chunks,tabs,output_file,col):
  |     if not empty(chunks):
  |        nextcol=col+length(first(chunks))
  |        write_string(output_file,first(chunks))
  |        if not empty(rest(chunks):
  |            aftertab=nexttab(tabs,nextcol)
  |            write_string(output_file,make_string(aftertab-nextcol,' '))
  |            output_with_tabs(rest(chunks),tabs,output_file,aftertab)
  |
  |  function next_tab(tabs,col):
  |      -- return the column reached when a TAB is at the column `col'.
  |      if periodic(tabs):
  |         period(tabs)*((col+1) div period(tabs))
  |      else:
  |         find_if( (lambda(tab): col<tab), tab_positions(tabs) ) or col -- if col >= all tabs.
  |*/

int main(){
    printf("not implemented yet\n");
    return 0;}
