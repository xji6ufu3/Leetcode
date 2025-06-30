int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int p1 = 0, p2 = 0, len = 0;
    while(1){
        while(p2 < numsSize && nums[p2] == nums[p1]) p2++;
        if(p2 == numsSize) break;
        int end = p2;
        while(end < numsSize && nums[end] == nums[p2]) end++;
        end--;
        if(nums[p2] - nums[p1] == 1 && len < end-p1+1) len = end-p1+1;
        p1 = p2;
        p2 = end+1;
    }
    return len;
}