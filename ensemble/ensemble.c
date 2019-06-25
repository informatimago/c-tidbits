#include <ensemble.h>
#include <util.h>
#include <list.h>
#include <stdlib.h>
#include <stdio.h>

void ensemble_print(ENSEMBLE* set){
    printf("{");
    const char* sep="";
    for(int i=0;i<set->m_cardinal;i++){
        printf("%s%d",sep,set->m_elements[i]);
        sep=",";
    }
    printf("}");
    printf("\n");
}


ENSEMBLE* ensemble_from_list(list_t* list){
    int count=length(list);

    ENSEMBLE* e=check_memory(malloc(sizeof(*e)));
    e->m_max=count;
    e->m_elements=check_memory(malloc(sizeof(e->m_elements[0])*e->m_max));
    e->m_cardinal=0;

    list_t* current=list;
    for(int i=0;current;i++,current=cdr(current)){
        e->m_elements[i]=car(current);
        e->m_cardinal++;
    }

    return e;}
