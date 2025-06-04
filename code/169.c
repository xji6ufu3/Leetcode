int majorityElement(int* nums, int numsSize) {
    int max = nums[0], num = 0;
    for(int i = 0;  i < numsSize; i++){
        if(nums[i] == max){
            num++;
        } else {
            num--;
            if(num < 0){
                max = nums[i];
                num = 0;
            }
        }
    }
    return max;
}