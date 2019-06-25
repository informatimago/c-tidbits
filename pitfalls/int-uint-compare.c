#include <stdio.h>

#define XWIDTH  7

int main(int argc, const char * argv[]) {
        
    int new_x = -3;
    unsigned int inward = 0;
        
    // Test 1 -- operates correctly
    if (new_x > XWIDTH/2) {
        printf("Test 1 Error! %d > %d.\n",new_x,XWIDTH/2);
    } else {
        printf("Test 1 Sanity prevails...\n");
    }
        
    // Test 2 -- operates incorrectly
    if (new_x > ((XWIDTH/2)-inward)) {
        printf("Test 2 Error! %d > %d.\n",new_x,((XWIDTH/2)-inward));
    } else {
        printf("Test 2 Sanity prevails...\n");
    }
    return 0;
}

