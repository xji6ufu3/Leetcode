int missingNumber(int* nums, int numsSize) {
    int total = numsSize*(numsSize+1)/2;
    for(int i = 0; i < numsSize; i++){
        total -= nums[i];
    }
    return total;
}