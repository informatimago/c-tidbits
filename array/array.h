#ifndef array_h
#define array_h
#include <stdlib.h>

typedef struct array *array;
typedef char         *cstring;
typedef wchar_t      *wstring;

void free_array(array a);

array make_array(size_t element_size,size_t rank,size_t* dimensions);
array make_vector(size_t element_size,size_t nelements,size_t fill_pointer);
array make_string(size_t length,char initial_character,size_t fill_pointer);
array make_string_from_cstring(const cstring string);
array make_string_from_wstring(const wstring string);
// make_array_displaced_to_array
// array_displacement

array array_copy(array a);
array adjust_array(array a,size_t rank,size_t* dimensions);

size_t array_rank(array a);
size_t array_dimension(array a,size_t dimension_index);
size_t array_element_size(array a);

size_t array_total_size(array a);
void array_row_major_set_element(void* new_element,array a,size_t index);
void array_row_major_get_element(void* old_element,array a,size_t index);

void array_set_element(void* new_element,array a,size_t* indices);
void array_get_element(void* old_element,array a,size_t* indices);
void array_fill(void* new_element,array a);

size_t vector_length(array a);
size_t vector_fill_pointer(array a);
void vector_set_fill_pointer(array a,size_t fill_pointer);

void vector_set_element(void* new_element,array a,size_t index);
void vector_get_element(void* old_element,array a,size_t index);
void vector_push(void* new_element,array* a);
void vector_pop(void* old_element,array* a);

typedef bool  (array_test_pr*)(void* element_a,void* element_b,size_t element_size,void* closure);
typedef void* (array_key_pr*)(void* element,size_t element_size,void* closure);
typedef bool  (array_predicate_pr*)(void* element,size_t element_size,void* closure);
typedef void* (array_mapper_pr*)(void* element,size_t element_size,void* closure);

array map(array_mapper_pr fun,array a,void* closure);

array vector_subseq(array a,size_t start,size_t end);
array vector_reverse(array a);
void vector_nreverse(array a);

void vector_fill(void* new_element,array a,size_t start,size_t end);

void* vector_find(size_t old_key_size,
                  void* old_key,
                  array a,size_t start,size_t end,
                  array_test_pr test,
                  array_key_pr key,
                  bool from_end,
                  void* closure);
void* vector_find_if(array_predicate_pr predicate,
                     array a,size_t start,size_t end,
                     array_key_pr key,
                     bool from_end,
                     void* closure);
void* vector_find_if_not(array_predicate_pr predicate,
                         array a,size_t start,size_t end,
                         array_key_pr key,
                         bool from_end,
                         void* closure);

size_t vector_position(size_t old_key_size,
                       void* old_key,
                       array a,size_t start,size_t end,
                       array_test_pr test,
                       array_key_pr key,
                       bool from_end,
                       void* closure);
size_t vector_position_if(array_predicate_pr predicate,
                          array a,size_t start,size_t end,
                          array_key_pr key,
                          bool from_end,
                          void* closure);
size_t vector_position_if_not(array_predicate_pr predicate,
                              array a,size_t start,size_t end,
                              array_key_pr key,
                              bool from_end,
                              void* closure);


size_t vector_count(size_t old_key_size,
                    void* old_key,
                    array a,size_t start,size_t end,
                    array_test_pr test,
                    array_key_pr key,
                    bool from_end,
                    void* closure);
size_t vector_count_if(array_predicate_pr predicate,
                       array a,size_t start,size_t end,
                       array_key_pr key,
                       bool from_end,
                       void* closure);
size_t vector_count_if_not(array_predicate_pr predicate,
                           array a,size_t start,size_t end,
                           array_key_pr key,
                           bool from_end,
                           void* closure);



cstring string_get_cstring(array a);
wstring string_get_wstring(array a);



#endif
