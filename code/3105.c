#include <stdio.h>

int longestMonotonicSubarray(int* nums, int numsSize) {
    enum {INCREASE, DECREASE, EQUAL} stat;
    int maxlen = 1, ptr = 1, len = 1;
    
    // init
    for(; ptr < numsSize; ++ptr){
        if(nums[ptr] > nums[ptr-1]){
            stat = INCREASE;
            maxlen = 2;
            len = 2;
            break;
        } else if(nums[ptr] < nums[ptr-1]){
            stat = DECREASE;
            maxlen = 2;
            len = 2;
            break;
        }
    }

    for(++ptr; ptr < numsSize; ++ptr){
        if(nums[ptr] > nums[ptr-1]){
            if(stat == INCREASE){
                ++len;
            } else{
                maxlen = maxlen > len ? maxlen : len;
                len = 2;
                stat = INCREASE;
            }
        } else if(nums[ptr] < nums[ptr-1]){
            if(stat == DECREASE){
                ++len;
            } else{
                maxlen = maxlen > len ? maxlen : len;
                len = 2;
                stat = DECREASE;
            }
        } else{
            len = 1;
            stat = EQUAL;
        }
    }

    maxlen = maxlen > len ? maxlen : len;

    return maxlen;
}
