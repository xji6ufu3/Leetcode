int minMoves(int* nums, int numsSize) {
    int themax = nums[0], sum = 0;

    for(int i = 0; i < numsSize; ++i){
        if(nums[i] > themax){
            sum += (nums[i] - themax) * i;
            themax = nums[i];
        } else{
            sum += themax - nums[i];
        }
    }

    return sum;
}