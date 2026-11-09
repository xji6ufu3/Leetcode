#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer = (int*)malloc(numsSize * sizeof(int)), p1Prod = 1, p2Prod = 1;

    for(int i = 0; i < numsSize; ++i){
        answer[i] = 1;
    }
    
    for(int i = 0, j = numsSize-1; i < numsSize; ++i, --j){
        answer[i] *= p1Prod;
        answer[j] *= p2Prod;
        p1Prod *= nums[i];
        p2Prod *= nums[j];
    }

    *returnSize = numsSize;
    return answer;
}
