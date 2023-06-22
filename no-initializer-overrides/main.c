

struct {
    int value;
} cells[3]= {
    [0 ... 2].value = 42,
    [1].value = -21,
};

int main(void){
    return cells[1].value+21;
}
