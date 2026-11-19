#include <stdlib.h>

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int minimizeSum(int* nums, int numsSize) {
    if(numsSize == 3) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    /**
     * diff1: remove smallest 2, the range of remains
     * diff2: remove largest 2, the range of remains
     * diff3: remove smallest and largest, the range of remains
     */
    int diff1, diff2, diff3;

    diff1 = nums[numsSize-1] - nums[2];
    diff2 = nums[numsSize-3] - nums[0];
    diff3 = nums[numsSize-2] - nums[1];

    int mindiff = diff1 < diff2 ? diff1 : diff2;
    
    mindiff = mindiff < diff3 ? mindiff : diff3;

    return mindiff;
}
