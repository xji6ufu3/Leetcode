int titleToNumber(char* columnTitle) {
    int size = strlen(columnTitle);
    long long sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum * 26 + columnTitle[i] - 'A' + 1;
    }
    return sum;
}