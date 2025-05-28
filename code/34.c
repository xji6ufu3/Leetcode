/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int binarySearch(int *nums, int size, int left, int right, int target, int mode){
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(mode == 0){
        if(nums[mid] == target){
            if(mid == 0){
                return 0;
            } else if(nums[mid-1] < target){
                return mid;
            } else{
                return binarySearch(nums, size, left, mid-1, target, mode);
            }
        } else if(target < nums[mid]){
            return binarySearch(nums, size, left, mid-1, target, mode);
        } else{
            return binarySearch(nums, size, mid+1, right, target, mode);
        }
    } else{
        if(nums[mid] == target){
            if(mid == size-1){
                return mid;
            } else if(target < nums[mid+1]){
                return mid;
            } else{
                return binarySearch(nums, size, mid+1, right, target, mode);
            }
        } else if(target < nums[mid]){
            return binarySearch(nums, size, left, mid-1, target, mode);
        } else{
            return binarySearch(nums, size, mid+1, right, target, mode);
        }
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = malloc(sizeof(int)*2);
    ans[0] = ans[1] = -1;
    if(numsSize == 0) return ans;
    ans[0] = binarySearch(nums, numsSize, 0, numsSize-1, target, 0);
    if(ans[0] != -1) ans[1] = binarySearch(nums, numsSize, ans[0], numsSize-1, target, 1);
    else ans[1] = -1;
    return ans;
}