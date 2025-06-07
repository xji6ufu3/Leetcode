/**
 * 只想到兩種做法
 * 1. 先 sort 再找重複，time: O(nlogn), space: O(1)
 * 2. 用 hash，但 C 的話好像只能開 bool hash[2*1e9];，雖然時間 O(n)，但空間 O(n) 太大
 * 2*1e9 byte 約為 2GB，消耗太多空間
 */

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] == nums[i+1]) return true;
    }
    return false;
}