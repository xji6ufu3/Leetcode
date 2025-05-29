char* addBinary(char* a, char* b) {
    int lena = strlen(a), lenb = strlen(b);
    if(lenb > lena){
        char* tmp = a;
        a = b;
        b = tmp;
        int tmp2 = lena;
        lena = lenb;
        lenb = tmp2;
    }
    char* str = malloc(sizeof(char) * (lena + 1 + 1));
    strcpy(str+1, a);
    int plus = 0;
    for(int i = 0; i < lenb; i++){
        str[lena-i] = (a[lena-i-1] + b[lenb-i-1] - '0'*2 + plus) % 2 + '0';
        plus = (a[lena-i-1] + b[lenb-i-1] - '0'*2 + plus) / 2;
    }
    for(int i = lenb; i < lena && plus; i++){
        str[lena-i] = (a[lena-i-1] + plus - '0') % 2 + '0';
        plus = (a[lena-i-1] + plus - '0') / 2;
    }
    str[0] = plus + '0';
    str[lena + 1] = '\0';
    return str[0]-'0' ? str : str+1;
}