#ifndef obj_h
#define obj_h




#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define unused(x) (x=x)

void* check_out_of_memory(void* memory,char* what){
    if(!memory){
        fprintf(stderr,"Out of memory: %s\n",what);
        exit(1);
    }
    return memory;
}



typedef void* id;
typedef char* SEL;
typedef id (*IMP)(id,SEL,...);
#define nil ((id)0)
#define SameSelector(a,b) (((a)==(b))||(0==strcmp(a,b)))

typedef struct method {
    SEL name;
    IMP implementation;
} method, *Method;

typedef struct methods {
    // TODO: use a hashtable
    int count;
    int allocated;
    Method* methods;
} methods, *Methods;

typedef struct class {
    struct class* metaclass; // isa
    struct class* superclass;
    Methods       methods;
    char*         name;
    int           isize;
} class;

typedef struct object {
    class* isa;
} object;


id nil_imp(id self,SEL _cmd,...){unused(self),unused(_cmd);return nil;}
method NilMethod={"nil_imp",nil_imp};

Methods Methods_new(){
    Methods methods=check_out_of_memory(malloc(sizeof(methods)),"Methods_new");
    methods->count=0;
    methods->allocated=8;
    methods->methods=check_out_of_memory(malloc(sizeof(method)*methods->allocated),"Methods_new->methods");
    return methods;
}

void Methods_extend(Methods methods,int allocatedIncrement){
    Method* newMethods=check_out_of_memory(malloc(sizeof(Method)*(methods->allocated+allocatedIncrement)),
                                           "Methods_extend.newMethods");
    memcpy(newMethods,methods->methods,sizeof(Method)*methods->count);
    free(methods->methods);
    methods->methods=newMethods;
    methods->allocated+=allocatedIncrement;
}

Method Class_findDirectInstanceMethod(class* self,SEL _cmd,SEL selector){
    unused(_cmd);
    int c=self->methods->count;
    Method* methods=self->methods->methods;
    for(int i=0;i<c;++i){
        if(SameSelector(selector,methods[i]->name)){
            return methods[i];
        }
    }
    return &NilMethod;
}

Method Class_findInstanceMethod(class* self,SEL _cmd,SEL selector){
    unused(_cmd);
    if(!self||!selector){
        return nil;
    }
    class* current=self;
    while(1){
        Method result=Class_findDirectInstanceMethod(current,"findDirectInstanceMethod",selector);
        if(result!=&NilMethod){
            return result;
        }
        if(current->superclass==current){
            return &NilMethod;
        }
        current=current->superclass;
    }
}

id Class_addMethod(class* self,SEL _cmd,SEL name,IMP implementation){
    unused(_cmd);
    Method method=Class_findDirectInstanceMethod(self,"findDirectInstanceMethod",name);
    if(method==&NilMethod){
        method=check_out_of_memory(malloc(sizeof(method)),"Class_addMethod.method");
        method->name=name;
        method->implementation=implementation;
        if(self->methods->count>=self->methods->allocated){
            Methods_extend(self->methods,8);
        }
        self->methods->methods[self->methods->count++]=method;
    }else{
        method->implementation=implementation;
    }
    return self;
}


Method instance_findMethod(id self,SEL _cmd,SEL selector){
    unused(_cmd);
    return self
            ?Class_findInstanceMethod(((object*)self)->isa,"findInstanceMethod",selector)
            :&NilMethod;
}

#define send(SELF,SELECTOR,...)                                         \
    instance_findMethod(SELF,#SELECTOR)->implementation(SELF,#SELECTOR,__ARGS__);



#define declare_class(NAME,SUPERCLASS)                                  \
    do{                                                                 \
        NAME.metaclass=&MetaClass;                                      \
        NAME.superclass=&SUPERCLASS;                                    \
        NAME.methods=Methods_new();                                     \
        NAME.name= #NAME ;                                              \
        NAME.isize=sizeof(NAME);                                        \
    }while(0)

class MetaClass;
class Class;
class Object;

void Class_initialize(){

    declare_class(MetaClass,Class);
    declare_class(Class,Object);
    declare_class(Object,Class);
    
}




void ObjectSystem_initialize(){
    MetaClass_initialize();
}
    





/* typedef struct name { */
/*     superclass* super; */
/*     int field; */
/* } name; */
/*  */
/*  */
/* result method(name* self,SEL _cmd,...){ */
/*      */
/* } */
