#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int len = strlen(s), anslen = 0, wordend;
    char *ans = (char*)malloc(len+5);

    for(int i = len-1; i >= 0; --i){
        while(i >= 0 && s[i] == ' ') --i;
        if(i < 0) break;

        wordend = i;

        while(i >= 0 && s[i] != ' ') --i;

        memcpy(ans+anslen, s+i+1, wordend - i);

        ans[anslen + wordend - i] = ' ';

        anslen += wordend - i + 1;
    }

    ans[anslen-1] = '\0';

    return ans;
}
