#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sysexits.h>


int optional_integer_argument(int argc,char** argv,int* next_argument,const char* option,int default_value){
    if((*next_argument)+1<argc){
        if(strcmp(argv[(*next_argument)],option)==0){
            (*next_argument)++;
            int value=atoi(argv[(*next_argument)]);
            (*next_argument)++;
            return(value);}}
    return(default_value);}

void check_end_of_arguments(int argc,char** argv,int next_argument){
    if(next_argument<argc){
        fprintf(stderr,"Superfluous arguments: %s\n",argv[next_argument]);
        exit(EX_USAGE);}}

void* check_pointer(void* pointer){
    if(pointer==NULL){
        fprintf(stderr,"malloc returned NULL\n");
        exit(EX_OSERR);}
    return(pointer);}

typedef char* cstring;
typedef struct string_node {
    cstring string;
    struct string_node* next;
} *string_circular_buffer;

string_circular_buffer make_string_circular_buffer(int number_of_nodes){
    if(number_of_nodes<=0){
        return(NULL);}
    string_circular_buffer first=check_pointer(malloc(sizeof(*first)));
    string_circular_buffer node=first;
    for(int i=1;i<number_of_nodes;i++){
        node->string=NULL;
        node->next=check_pointer(malloc(sizeof(*node)));
        node=node->next;}
    node->string=NULL;
    node->next=first;
    return(first);}

/*
buffer -> [l-10] -> [l-9] … -> [l-2]  -> [l-1] --+
           ^                                     |
           |                                     |
           +-------------------------------------+
*/

void string_circular_buffer_enter(string_circular_buffer* buffer,cstring line){
    if((*buffer)->string!=NULL){
        free((*buffer)->string);}
    (*buffer)->string=line;
    (*buffer)=(*buffer)->next;}

void print_string_circular_buffer_1(FILE* output,string_circular_buffer buffer,string_circular_buffer current){
    printf("%s\n",current->string);
    if(current->next!=buffer){
        print_string_circular_buffer_1(output,buffer,current->next);}}

void print_string_circular_buffer(FILE* output,string_circular_buffer buffer){
    print_string_circular_buffer_1(output,buffer,buffer);}

cstring read_line(FILE* input){
    static char bigbuffer[0x100000];
    char* line=fgets(bigbuffer,sizeof(bigbuffer),input);
    if(line==NULL){
        return(NULL);}
    size_t len=strlen(line);
    if(len==0){
        // impossible
        fprintf(stderr,"Got an impossible result from fgets: result is empty string!\n");
        exit(EX_SOFTWARE);}
    else if(line[len-1]=='\n'){
        line[len-1]='\0';
        return(strdup(line));}
    else {
        fprintf(stderr,"Warning: line too long (more than %lu) or end-of-file with an unterminated line.\n",sizeof(bigbuffer));
        exit(EX_DATAERR);}}

void tail(FILE* input,FILE* output,string_circular_buffer buffer){
    cstring line;
    while(NULL!=(line=read_line(input))){
        string_circular_buffer_enter(&buffer,line);}
    print_string_circular_buffer(output,buffer);}

int main(int argc,char** argv){
    int i=1;
    int number_of_lines=optional_integer_argument(argc,argv,&i,"-n",10);
    check_end_of_arguments(argc,argv,i);
    string_circular_buffer buffer=make_string_circular_buffer(number_of_lines);
    tail(stdin,stdout,buffer);
    return(0);}
