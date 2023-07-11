#include <stdio.h>

#define CALL_void(retype,fname,arguments) fname arguments
#define CALL_RETURN(retype,fname,arguments) return (retype) fname arguments

#define CALL(retype,fname,arguments) \
    CALL_##retype(fname,arguments) 


















#if 0
#define CALL_VOID(fname,arguments) fname arguments
#define CALL_return(retype, fname,arguments) return (retype) fname arguments
#define call(retype, fname,arguments)                                   \
    _Generic(retype,                                                    \
             void: CALL(fname,arguments),                               \
             default:  CALL_RETURN(retype,fname,arguments))

void foo(int x){
    printf("foo %d\n", x);
}
int bar(int x){
    printf("bar %d\n", x);
    return 1+x;
}
int main(){
    call(void, foo, (1));
    call(int, bar, (1));
    return 0;
}
#endif
