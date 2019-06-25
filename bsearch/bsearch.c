#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <gc.h>

#ifdef __GNUC__
#include <execinfo.h>
#define MAX_FRAMES 128
void print_backtrace(){
    void* buffer[MAX_FRAMES];
    int size=backtrace(buffer,MAX_FRAMES);
    backtrace_symbols_fd(buffer,size,2);}
#else
void print_backtrace(){}
#endif

int verbose=1;
typedef int64_t integer8;
typedef enum t_type{type_string=574129,type_vector=23707} type_t;

typedef struct object
{
    enum t_type         type;
    integer8            extension_type;
    void                *descripteur_bibliotheque;
    volatile long       nombre_occurrences;
    pthread_mutex_t     mutex;
    void                *object;
} object_t;

typedef struct vector
{
    integer8            capacity;
    integer8            nombre_elements;
    object_t          **elements;
} vector_t;

void error(const char* function,int line,char* message,...){
    va_list args;
    va_start(args,message);
    int size=vsnprintf(NULL,0,message,args);
    va_end(args);
    char* buffer=GC_MALLOC(size+1);
    if(buffer==0){
        buffer=message;}
    else{
        va_start(args,message);
        vsnprintf(buffer,size+1,message,args);
        va_end(args);
    }
    fprintf(stderr,"%s:%d: %s\n",function,line,buffer);
    print_backtrace();
    exit(1);}

#define ERROR(message,...) error(__FILE__,__LINE__,message,##__VA_ARGS__)

void*check_memory(void* mem){
    if(mem){return mem;}
    ERROR("Out of memory");
    return NULL;}

vector_t* vector_new(integer8 capacity){
    vector_t* that=check_memory(GC_MALLOC(sizeof(*that)));
    that->capacity=capacity;
    that->nombre_elements=0;
    that->elements=check_memory(GC_MALLOC(sizeof(that->elements[0])*capacity));
    return that;}

void vector_add_element(vector_t* that,object_t* element){
    if(that->nombre_elements>=that->capacity){
        ERROR("out of capacity");}
    that->elements[that->nombre_elements++]=element;}

integer8 vector_length(vector_t* that){
    return that->nombre_elements;}

object_t* vector_ref(vector_t* that,integer8 index){
    if((index<0)||(that->nombre_elements<=index)){
        ERROR("out of bound");}
    return that->elements[index];}

type_t object_type(object_t* that){
    return that->type;}

object_t* object_allocate(type_t type){
    object_t* that=check_memory(GC_MALLOC(sizeof(*that)));
    that->type=type;
    that->extension_type=0;
    that->descripteur_bibliotheque=NULL;
    that->nombre_occurrences=0;
    pthread_mutex_init(&that->mutex,NULL);
    that->object=NULL;
    return that;}

object_t* object_new_string(char* string){
    object_t* that=object_allocate(type_string);
    that->object=string;
    return that;}

object_t* object_new_vector(vector_t* vector){
    object_t* that=object_allocate(type_vector);
    that->object=vector;
    return that;}

char* object_string(object_t* that){
    if(that->type!=type_string){
        ERROR("type error, string expected instead of type %d",that->type);}
    return that->object;}

vector_t* object_vector(object_t* that){
    if(that->type!=type_vector){
        ERROR("type error, vector expected instead of type %d",that->type);}
    return that->object;}

void vector_free(vector_t* that);
void object_free(object_t* that){
    switch(that->type){
      case type_string:free(object_string(that)); break;
      case type_vector:vector_free(object_vector(that)); break;}
    pthread_mutex_destroy(&that->mutex);}

void vector_free(vector_t* that){
    while(that->nombre_elements>0){
        object_free(vector_ref(that,that->nombre_elements-1));
        that->nombre_elements--;}
    free(that->elements);
    free(that);}

void string_print(char* string){
    // TODO: escape \ and " in string:
    printf("\"%s\"",string);}

void vector_print(vector_t* that);

void object_print(object_t* that){
    switch(object_type(that)){
      case type_string:string_print(object_string(that));break;
      case type_vector:vector_print(object_vector(that));break;}}

void vector_print(vector_t* that){
    printf("(");
    char* sep="";
    for(int i=0;i<that->nombre_elements;i++){
        printf("%s",sep);
        object_print(vector_ref(that,i));
        sep=" ";}
    printf(")");}

void test(){
    object_t* string=object_new_string("Hello");
    printf("A string: ");object_print(string);printf("\n");
    vector_t* vector=vector_new(8);
    vector_add_element(vector,object_new_string("foo"));
    vector_add_element(vector,object_new_string("bar"));
    vector_add_element(vector,object_new_string("baz"));
    printf("A vector: ");vector_print(vector); printf("\n");
    object_t* object=object_new_vector(vector);
    printf("A vector in an object: ");object_print(object);printf("\n");}

object_t* make_data(){
    /* ("foo" ("foo" "bar") "bar" ("bar" "foo" "baz") "baz") */
    vector_t* sub;
    vector_t* vector=vector_new(8);
    vector_add_element(vector,object_new_string("foo"));
    sub=vector_new(8);
    vector_add_element(sub,object_new_string("foo"));
    vector_add_element(sub,object_new_string("bar"));
    vector_add_element(vector,object_new_vector(sub));
    vector_add_element(vector,object_new_string("bar"));
    sub=vector_new(8);
    vector_add_element(sub,object_new_string("bar"));
    vector_add_element(sub,object_new_string("foo"));
    vector_add_element(sub,object_new_string("baz"));
    vector_add_element(vector,object_new_vector(sub));
    vector_add_element(vector,object_new_string("baz"));
    return object_new_vector(vector);}

int vector_compare(vector_t* va,vector_t* vb);

int object_compare(object_t** pa,object_t** pb){
    object_t* a=*pa;
    object_t* b=*pb;
    int result=0;
    /* strings are smaller than vectors */
    switch(object_type(a)){
      case type_string:
          switch(object_type(b)){
            case type_string:
                result=strcmp(object_string(a),object_string(b));
                break;
            case type_vector:
                result=-1;
                break;}
          break;
      case type_vector:
          switch(object_type(b)){
            case type_string:
                result=+1;
                break;
            case type_vector:
                result=vector_compare(object_vector(a),object_vector(b));
                break;}
          break;}
    if(verbose){
        printf("compare "); object_print(a); printf(" vs. "); object_print(b); printf(" -> %d\n",result);}
    return result;}

int vector_compare(vector_t* va,vector_t* vb){
    integer8 la=vector_length(va);
    integer8 lb=vector_length(vb);
    integer8 i=0;
    object_t* a=vector_ref(va,i);
    object_t* b=vector_ref(vb,i);
    while((i<la)&&(i<lb)&&(0==object_compare(&a,&b))){
        i++;}
    if(i==la){
        if(i==lb){
            return 0;}
        else{
            return -1;}}
    else{
        return +1;}}

typedef int (*compar) (const void *, const void *);
void vector_sort(vector_t* that){
    qsort(that->elements,
          (size_t)that->nombre_elements,
          sizeof(object_t*),
          (compar)object_compare);}

object_t** vector_search(vector_t* that,object_t* key){
    return bsearch(&key,
                   that->elements,
                   (size_t)that->nombre_elements,
                   sizeof(object_t*),
                   (compar)object_compare);}

int main(){
    if(verbose){
        test();}
    object_t* object=make_data();
    if(verbose){
        printf("Before sort: "); object_print(object); printf("\n");}
    vector_sort(object_vector(object));
    if(verbose){
        printf("After  sort: "); object_print(object); printf("\n");}
    object_t** found=vector_search(object_vector(object),object_new_string("bar"));
    if(found==NULL){
        printf("object bar not found\n");}
    else{
        printf("object bar found: "); object_print(*found); printf("\n");}
    return 0;}
