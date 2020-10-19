#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
* Complete the 'findSubstring' function below.
*
* The function is expected to return a STRING.
* The function accepts following parameters:
*  1. STRING s
*  2. INTEGER k
*/

/*
* To return the string from the function, you should either do static allocation or dynamic allocation
*
* For example,
* char* return_string_using_static_allocation() {
*     static char s[] = "static allocation of string";
*
*     return s;
* }
*
* char* return_string_using_dynamic_allocation() {
*     char* s = malloc(100 * sizeof(char));
*
*     s = "dynamic allocation of string";
*
*     return s;
* }
*
*/
int vowelp(char c){
    return 0!=strchr("aeiou",c);}

int vowelCount(char* s,int i,int k){
    int v=0;
    for(int j=0;j<k;j++){
        if(vowelp(s[i+j])){
            v++;}}
    return v;}

void* check_pointer(void* p){
    if(p){return p;}
    fprintf(stderr,"Out of memory\n");
    exit(1);}

char* findSubstring(char* s, int k) {
    int e=strlen(s)-k;
    if((k==0)||(e<0)){
        return "";}
    int v=vowelCount(s,0,k);
    int w=v;
    int m=(v>0)?0:-1;
    for(int i=1;i<=e;i++){
        if(vowelp(s[i-1])){
            w--;}
        if(vowelp(s[i+k-1])){
            w++;}
        if(v<w){
            m=i;
            v=w;}}
    if(m<0){
        return "Not found!";}
    char* result=check_pointer(malloc(k+1));
    strncpy(result,s+m,k);
    result[k]='\0';
    return result;}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    int k = parse_int(ltrim(rtrim(readline())));

    char* result = findSubstring(s, k);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
