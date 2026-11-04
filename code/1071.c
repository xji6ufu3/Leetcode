#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    
    if(len2 > len1){
        char *ctmp = str1;
        str1 = str2;
        str2 = ctmp;

        int ltmp = len1; 
        len1 = len2;
        len2 = ltmp;
    }

    int xlen = 0, ptr = 0, shift = 1;

    for(; (xlen < len2) && (str1[xlen] == str2[xlen]); ++xlen);

    for(; ptr + shift < xlen; ++ptr){
        if(str2[ptr] != str2[ptr + shift]){
            ptr = -1;
            ++shift;
        }
    }

    int cnt1 = 0, cnt2 = 0;
    
    if(!(len1 % shift)){
        while(cnt1 * shift < len1){
            if(!strncmp(str1 + cnt1 * shift, str2, shift)){
                ++cnt1;
            } else{
                cnt1 = 0;
                break;
            }
        }
    }
    if(!(len2 % shift)){
        while(cnt2 * shift < len2){
            if(!strncmp(str2 + cnt2 * shift, str2, shift)){
                ++cnt2;
            } else{
                cnt2 = 0;
                break;
            }
        }
    }

    printf("xlen: %d, cnt1: %d, cnt2: %d\n", xlen, cnt1, cnt2);

    xlen = cnt1 == 0 || cnt2 == 0 ? 0 :gcd(cnt1, cnt2) * shift;

    printf("xlen: %d\n", xlen);
    
    char *x = (char *)malloc(xlen+1);
    strncpy(x, str2, xlen);
    x[xlen] = '\0';

    return x;
}

int main(){
    char *str1, *str2;
    int len1, len2;
    
    printf("len1, len2: ");
    scanf("%d%d", &len1, &len2);

    str1 = (char*)malloc(len1 + 1);
    str2 = (char*)malloc(len2 + 1);

    printf("str1:\n");
    scanf("%s", str1);
    printf("str2:\n");
    scanf("%s", str2);

    char *ret = gcdOfStrings(str1, str2);

    printf("ans: %s\n", ret);

    free(ret);
    free(str1);
    free(str2);

    return 0;
}