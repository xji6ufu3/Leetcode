#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    bool check[numsSize];
    int leftMin = __INT_MAX__, rightMax = INT_MIN;

    for(int i = 0; i < numsSize; ++i){
        check[i] = leftMin < nums[i];
        leftMin = check[i] ? leftMin : nums[i];
    }

    for(int i = numsSize-1; i; --i){
        if(nums[i] < rightMax && check[i]) return true;
        rightMax = nums[i] < rightMax ? rightMax : nums[i];
    }

    return false;
}
