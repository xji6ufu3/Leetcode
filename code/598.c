int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int a = m, b = n;
    for(int i = 0; i < opsSize; i++){
        if(ops[i][0] < a) a = ops[i][0];
        if(ops[i][1] < b) b = ops[i][1];
    }
    return a*b;
}