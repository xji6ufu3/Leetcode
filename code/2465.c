int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int distinctAverages(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    bool avg[201] = {0};
    int ans = 0;
    for(int i = 0; i <numsSize/2; ++i){
        int ptr = nums[i]+nums[numsSize-i-1];
        if(!avg[ptr]){
            avg[ptr] = true;
            ++ans;
        }
    }
    return ans;
}