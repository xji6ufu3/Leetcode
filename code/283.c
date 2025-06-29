void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;  // non-zero position
    for(int i = 0; i < numsSize; i++){
        // put all non-zero elements forward, skip the 0
        if(nums[i]) nums[cnt++] = nums[i];
    }
    for(; cnt < numsSize; cnt++){
        // fill the 0 backward
        nums[cnt] = 0;
    }
}