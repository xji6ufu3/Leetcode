// use KMP algorithm, find LPS array

#include<stdio.h>
#include<string.h>

void getLPSarray(char *pattern, int *lps){
    int prev = 0, i = 1, plen = strlen(pattern);
    lps[0] = 0;
    while(i < plen){
        if(pattern[prev] == pattern[i]){
            lps[i++] = prev++ + 1;
        } else if(prev == 0){
            lps[i++] = 0;
        } else {
            prev = lps[prev - 1];
        }
    }
}

int strStr(char* haystack, char* needle) {
    int lps[strlen(needle)];
    getLPSarray(needle, lps);
    int i =  0, j = 0, slen = strlen(haystack), plen = strlen(needle);
    while(i < slen){
        if(haystack[i]  == needle[j]){
            i++;
            j++;
        } else {
            j ? j = lps[j - 1] : ++i;
        }
        if(j == plen) return i - plen;
    }
    return -1;
}