#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int cnt = 0, tmpcnt = 0;
    for(int i = 0; i < flowerbedSize; ++i){
        if(flowerbed[i]){
            if(tmpcnt) --tmpcnt;
            printf("i: %d, cnt: %d, tmpcnt: %d, add: %d\n", i, cnt, tmpcnt, tmpcnt / 2 + tmpcnt % 2);
            cnt += tmpcnt / 2 + tmpcnt % 2;
            while(i < flowerbedSize && flowerbed[i]) ++i;
            tmpcnt = 0;
        } else{
            ++tmpcnt;
        }
    }
    cnt += tmpcnt / 2 + tmpcnt % 2;
    printf("cnt: %d\n", cnt);
    return cnt >= n;
}
