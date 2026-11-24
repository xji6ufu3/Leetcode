#include <stdio.h>

long long getGCD(long long a, long long b){
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }

    return a;
}

int maxLength(int* nums, int numsSize) {
    int window_size = numsSize;

    for(bool state = false; window_size >= 2; --window_size){
        for(int i = 0; i < numsSize-1; ++i){
            int gcd = nums[i], lcm = nums[i], x = 1;

            for(int j = i+1; j < numsSize && j-i < window_size; ++j){
                gcd = getGCD(gcd, nums[j]);
                printf("gcd: %d\n", gcd);
            }

            for(int j = i+1; j < numsSize && j-i < window_size; ++j){
                int x_gcd = getGCD(lcm, nums[j]);
                x *= x_gcd;
                state = x == gcd;
                lcm *= nums[j] / x_gcd;
                printf("x: %d, x_gcd: %d, state: %d, lcm: %d\n", x, x_gcd, state, lcm);
                if(gcd % x || x >= gcd) break;
            }

            if(state) break;
        }

        if(state) break;
    }

    return window_size;
}
