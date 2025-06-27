char* countAndSay(int n) {
    int cap = 128;
    char* str = malloc(cap);
    int len = 0;
    str[len++] = '1';
    int newlen = 0, newcap = cap;
    char* newstr = malloc(newcap);
    for(int i = 1; i < n; i++){
        newlen = 0;
        int target = str[0] - '0', cnt = 1;
        for(int j = 1; j < len; j++){
            if(target == str[j]-'0'){
                cnt++;
            } else {
                if(newlen+2+1 > newcap){ // +1 for the \0
                    newcap *= 2;
                    newstr = realloc(newstr, newcap);
                }
                newstr[newlen++] = cnt + '0';
                newstr[newlen++] = target + '0';
                target = str[j] - '0';
                cnt = 1;
            }
        }
        if(newlen+2+1 > newcap){
            newcap *= 2;
            newstr = realloc(newstr, newcap);
        }
        newstr[newlen++] = cnt + '0';
        newstr[newlen++] = target + '0';
        
        char* tmp = str;
        str = newstr;
        newstr = tmp;
        len = newlen;
        int itmp = cap;
        cap = newcap;
        newcap = itmp;
    }
    str[len] = 0;
    return str;
}