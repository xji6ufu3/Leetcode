bool isvowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    char *ans = malloc(len+1);
    strcpy(ans, s);
    int left = 0, right = len-1;
    while(1){
        while(left < len && !isvowel(ans[left])) left++;
        while(right >= 0 && !isvowel(ans[right])) right--;
        if(left >= right) break;
        char c = ans[left];
        ans[left] = ans[right];
        ans[right] = c;
        left++;
        right--;
    }
    return ans;
}