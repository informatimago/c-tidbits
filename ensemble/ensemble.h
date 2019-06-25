#ifndef ensemble_h
#define ensemble_h
#include <list.h>

struct ensemble {
    int m_max;
    int m_cardinal;
    int * m_elements;
};
typedef struct ensemble ENSEMBLE;

void ensemble_print(ENSEMBLE* set);
ENSEMBLE* ensemble_from_list(list_t* list);

#endif
