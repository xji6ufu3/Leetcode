#include <stdio.h>

int compress(char* chars, int charsSize) {
    int ptr = 1, cnt = 1;
    char c = chars[0];

    for(int i = 1; i < charsSize; ++i){
        if(c == chars[i]){
            ++cnt;
        } else{
            if(cnt > 1){
                int power = 1000;

                while(power && cnt / power == 0){
                    power /= 10;
                }
                while(power){
                    chars[ptr++] = '0' + cnt / power;
                    cnt %= power;
                    power /= 10;
                }
            }

            chars[ptr++] = chars[i];
            c = chars[i];
            cnt = 1;
        }
    }

    if(cnt > 1){
        int power = 1000;

        while(power && cnt / power == 0){
            power /= 10;
        }
        while(power){
            chars[ptr++] = '0' + cnt / power;
            cnt %= power;
            power /= 10;
        }
    }
    

    return ptr;
}
