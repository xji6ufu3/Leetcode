/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct pair{
    int loc;
    int val;
};

int cmp(const void* a, const void* b){
    return ((struct pair*)b)->val - ((struct pair*)a)->val;
}

int cmp2(const void* a, const void* b){
    return ((struct pair*)a)->loc - ((struct pair*)b)->loc;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    struct pair p[numsSize];
    for(int i = 0; i < numsSize; i++){
        p[i].loc = i;
        p[i].val = nums[i];
    }
    qsort(p, numsSize, sizeof(struct pair), cmp);
    qsort(p, k, sizeof(struct pair), cmp2);
    int* ans = malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) ans[i] = p[i].val;
    *returnSize = k;
    return ans;
}