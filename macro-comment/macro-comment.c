#define comment(x) /* x                                                 \
                   x */

/* #define C /\* */
/* #define E *\/ */
/* C this would be comment E */

#define complex(x) \
    /* This is 
       a multiline
       comment */ \
    x

int main(){
    int foo=42;
    complex(foo*=2);
    comment(whatever);
    foo=foo/2;
    return 0;}

/*
gcc -E -o macro-comment.e macro-comment.c && cat macro-comment.e

# 1 "macro-comment.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "macro-comment.c"
# 14 "macro-comment.c"
int main(){
    int foo=42;
    foo*=2;
    ;
    foo=foo/2;
    return 0;}

*/
