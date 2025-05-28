/*
改造二分法，如果 nums[l] < nums[r] 代表仍處於有序狀態，用一般的二分法可找出解
如果 nums[l] > nums[r] 代表處於有翻轉的狀態，要分情況
如果 target 小於 nums[r] 或大於 nums[l]，則像是一般二分法那樣直接切，通常第一刀都是這樣。
找到 mid 後，mid 有兩種情況，一種是 nums[mid] > nums[l]，則判斷 target 是否介於 nums[l] 到 nums[mid] 之間
若是，則 l = l，r = mid，接續普通的二分法
若否，則必然是在 mid 到 r 之間， l = mid，r = r。
面對 nums[mid] < nums[r] 的情況也是如同以上的作法。 
*/

int binarySearch(int *nums, int numsSize, int left, int right, int target){
    printf("left: %d, right: %d\n", left, right);
    if(left < 0 || left == numsSize || right < 0 || right == numsSize) return -1;
    if(target == nums[left]) return left;
    else if(target == nums[right]) return right;
    else if(left >= right) return -1;
    int mid = (right + left) / 2;
    if(target == nums[mid]) return mid;
    if(nums[left] < nums[right]){
        if(nums[left] < target && target < nums[mid]) return binarySearch(nums, numsSize, left, mid-1, target); 
        else if(nums[mid] < target && target < nums[right]) return binarySearch(nums, numsSize, mid+1, right, target);
        else return -1;
    } else{
        if(nums[right] < target && target < nums[left]) return -1;
        if(nums[left] < nums[mid]){
            if(nums[left] < target && target < nums[mid]) return binarySearch(nums, numsSize, left, mid-1, target);
            else return binarySearch(nums, numsSize, mid+1, right, target);
        } else {
            if(nums[mid] < target && target < nums[right]) return binarySearch(nums, numsSize, mid+1, right, target);
            else return binarySearch(nums, numsSize, left, mid-1, target);
        }
    }
}

int search(int* nums, int numsSize, int target) {
    return binarySearch(nums, numsSize, 0, numsSize-1, target);
}