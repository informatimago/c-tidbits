#include <stdio.h>
int main(void){
    void (^f)() = ^{
        for (int i = 0; i < 5; i++)
            printf("%d\n", i);
    };
    f();
    return 0;
}
