void sortColors(int* nums, int numsSize) {
    int left = 0, right = numsSize-1, tmp, i = 0; // left 為可存放 0 的位置， right 為可存放 2 的位置
    while(i <= right){
        if(nums[i] == 0){
            tmp = nums[left];
            nums[left++] = nums[i];
            nums[i++] = tmp;
        } else if(nums[i] == 2){
            tmp = nums[right];
            nums[right--] = nums[i];
            nums[i] = tmp;
        } else {
            i++;
        }
    }
}