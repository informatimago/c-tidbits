void f(){
    static int* p;
    static int* q;
    static int* h;
    p=0;
    q=(int*)0xdeadface;
    h=(int*)0xffffff01;
}

int main(){
    f();
    return 0;}
