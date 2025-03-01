#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) {
    char str[40];
    // itoa(x, str, 10);
    sprintf(str, "%d", x);
    int start=0, end=strlen(str)-1;
    if(str[0]=='-'){
        start=1;
    }
    bool result=true;
    for(; start<end; ++start, --end){
        if(str[start]!=str[end]){
            result=false;
            break;
        }
    }
    return result;
}
int main(){
    int x;
    printf("scan an integer: ");
    scanf("%d", &x);
    printf("result: %d\n", isPalindrome(x));
}