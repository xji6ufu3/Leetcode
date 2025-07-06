int countKDifference(int* nums, int numsSize, int k) {
    int cnt[100] = {0}, ans = 0;
    for(int i = 0; i < numsSize; i++){
        int n = nums[i];
        ans += n-k >= 1 ? cnt[n-k-1] : 0;
        ans += n+k <= 100 ? cnt[n+k-1] : 0;
        ++(cnt[n-1]);
    }
    return ans;
}