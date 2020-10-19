struct part {
    int line;
    char partID[20];
};


int main(){
    struct part p0;
    struct part p1={0,"Hello"};
    p0=p1;
    return 0;}

    
