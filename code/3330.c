int possibleStringCount(char* word) {
    int len = strlen(word);
    int sum = 1, cnt = 0, ptr = 0;
    while(ptr < len){
        int ptr2 = ptr;
        while(ptr2 < len && word[ptr2] == word[ptr]) ptr2++;
        sum += ptr2 - ptr - 1;
        ptr = ptr2;
    }
    return sum;
}