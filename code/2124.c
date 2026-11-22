#include <string.h>
#include <stdbool.h>

bool checkString(char* s) {
    bool is_b_appear = false;
    int s_len = strlen(s);

    for(int i = 0; i < s_len; ++i){
        char c = s[i];
        if(is_b_appear){
            if(c == 'a') return false;
        } else{
            if(c == 'b') is_b_appear = true;
        }
    }
    
    return true;
}
