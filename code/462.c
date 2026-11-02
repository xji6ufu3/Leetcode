int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int midptr = numsSize / 2;
    int mid = nums[midptr], sum = 0;

    for(int i = 0; i < numsSize; ++i){
        int num = nums[i];
        if(mid - num > 0){
            sum += mid - num;
        } else{
            sum += num - mid;
        }
    }

    return sum;
}