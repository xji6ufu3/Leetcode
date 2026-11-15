#include <stdlib.h>
#include <stdio.h>

int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int range =  r - l;
    int *win = (int*)malloc((range+1) * sizeof(int));
    int sum = 0, smallest = -1;

    for(int i = 0; i < l; ++i){
        sum += nums[i];
    }

    win[0] = sum;
    smallest = sum > 0 ? (smallest == -1 ? sum : (smallest < sum ? smallest : sum)) : smallest;


    for(int i = 1; i <= range && i+l-1 < numsSize; ++i){
        win[i] = win[i-1] + nums[i+l-1];
        smallest = win[i] > 0 ? (smallest == -1 ? win[i] : (smallest < win[i] ? smallest : win[i])) : smallest;
    }

    for(int i = 1; i < numsSize; ++i){
        for(int j = 0; j <= range && i+j+l-1 < numsSize; ++j){
            win[j] = win[j] - nums[i-1] + nums[i+j+l-1];
            smallest = win[j] > 0 ? (smallest == -1 ? win[j] : (smallest < win[j] ? smallest : win[j])) : smallest;
        }
    }

    free(win);

    return smallest;
}
