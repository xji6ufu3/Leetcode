int firstUniqChar(char* s) {
    bool appear[26] = {0}, repeat[26] = {0};
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        char c = s[i];
        if(!appear[c-'a']) appear[c-'a'] = true;
        else repeat[c-'a'] = true;
    }
    for(int i = 0; i < len; i++){
        if(!repeat[s[i]-'a']) return i;
    }
    return -1;
}