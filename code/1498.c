int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int pow2(int power){
    int cnt = 1;
    for(int i = 0; i < power; i++) cnt *= 2;
    return cnt;
}

int numSubseq(int* nums, int numsSize, int target) {
    // 題目要求，所有答案要 mod (1e9 + 7)
    const int MOD = 1e9 + 7;
    
    // 先建表，節省運算時間
    int pow2[100005];
    pow2[0] = 1;
    for(int i = 1; i <= numsSize; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    int cnt = 0, left = 0, right = numsSize-1;
    
    // 雙指標，更省時
    while(left <= right){ // 必取 left，從 left+1 ~ right 可取可不取
        if(nums[left] + nums[right] <= target){
            cnt = (cnt + pow2[right - left]) % MOD;
            left++;
        } else {
            right--;
        }
    }

    return cnt;
}