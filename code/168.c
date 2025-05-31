char* convertToTitle(int columnNumber) {
    char ans[7];
    int num = 0, quotient = columnNumber, remainder;
    do{
        quotient -= 1;
        remainder = quotient % 26;
        quotient /= 26;
        ans[num++] = 'A' + remainder;
    }while(quotient);
    char* ret = malloc(sizeof(char) * (num+1));
    for(int i = 0; i < num; i++) ret[i] = ans[num-i-1];
    ret[num] = '\0';
    return ret;
}