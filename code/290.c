bool wordPattern(char* pattern, char* s) {
    char patt[26][305];
    char str[305];
    while(sscanf(s, "%s", str) != EOF){
        char c;
        if(sscanf(pattern, "%c", &c) == EOF) return false;
        if(strlen(patt[c-'a'])){
            if(strcmp(str, patt[c-'a']) != 0) return false;
        } else {
            for(int i = 0; i < 26; i++){
                if(!strcmp(str, patt[i])) return false;
            }
            strcpy(patt[c-'a'], str);
        }
        pattern += 1;
        s += strlen(str)+1;
    }
    if(strlen(pattern)) return false;
    return true;
}