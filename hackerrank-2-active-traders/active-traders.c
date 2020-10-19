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
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */

void* check_pointer(void* p){
    if(p){return p;}
    fprintf(stderr,"Out of memory\n");
    exit(1);}


typedef struct {
    char* customer;
    int count;
    float percent;
} customer_info;

int grossium_order(const void* a,const void* b){
    const char** sa=(const char**)a;
    const char** sb=(const char**)b;
    return strcmp(*sa,*sb);}

void print_customers(int cis_count,char** customer,int* activity){
    for(int i=0;i<cis_count;i++){
        printf("%-30s %8d\n",customer[i],activity[i]);}}

int find_customer(int cis_count,char** cis_customer,char* customer){
    for(int i=0;i<cis_count;i++){
        if(0==strcmp(customer,cis_customer[i])){
            return i;}}
    return -1;}

#define HASH_SIZE (499979)
char* names[HASH_SIZE]={0};
int   trades[HASH_SIZE]={0};

int hash1(char* customer){
    int h=0;
    while(*customer){
        h = (h << 4) + *(customer);
		long g = h & 0xF0000000L;
		if (g != 0) { h ^= (g >> 24); }
		h &= ~g;
        customer++;}
    return h%HASH_SIZE;}

int hash2(char* customer){
    int h=0;
    while(*customer){
        h=0xfffffff&((h*31)+(*customer));
        customer++;}
    return h%HASH_SIZE;}

int get_hash_slot(char* customer){
    int h1=hash1(customer);
    int h2=hash2(customer);
    while((0!=names[h1])&&(0!=strcmp(names[h1],customer))){
        h1=(h1+h2)%HASH_SIZE;}
    return h1;}

void test_hash(int customers_count, char** customers) {
    int cis_count=0;
    for(int i=0;i<customers_count;i++){
        int c=get_hash_slot(customers[i]);
        if(names[c]==0){
            names[c]=customers[i];
            cis_count++;}}
    int overflow=0;
    int increment=0;
    for(int i=0;i<customers_count;i++){
        int h1=hash1(customers[i]);
        int h2=hash2(customers[i]);
        if(0!=strcmp(names[h1],customers[i])){
            overflow++;
            while(0!=strcmp(names[h1],customers[i])){
                increment++;
                h1=(h1+h2)%HASH_SIZE;}}}
    printf("hash overflow:  %d\n",overflow);
    printf("hash increment: %d\n",increment);}

char** mostActive(int customers_count, char** customers, int* result_count) {
    test_hash(customers_count, customers);
    printf("tested\n");fflush(stdout);
    int cis_count=0;
    for(int i=0;i<customers_count;i++){
        int c=get_hash_slot(customers[i]);
        if(names[c]==0){
            names[c]=customers[i];
            cis_count++;}
        else{
            trades[c]++;}}

    int grossiums_count=0;
    for(int i=0;(i<HASH_SIZE)&&(grossiums_count<20);i++){
        if(names[i]&&(((float)trades[i]>=0.05*customers_count))){
            names[grossiums_count]=names[i];
            grossiums_count++;}}

    qsort(names,grossiums_count,sizeof(*names),
          grossium_order);

    char** result=names;
    (*result_count)=grossiums_count;
    return result;}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int customers_count = parse_int(ltrim(rtrim(readline())));

    char** customers = malloc(customers_count * sizeof(char*));

    for (int i = 0; i < customers_count; i++) {
        char* customers_item = readline();

        *(customers + i) = customers_item;
    }

    int result_count;
    char** result = mostActive(customers_count, customers, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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
