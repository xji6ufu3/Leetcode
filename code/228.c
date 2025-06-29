/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if(!numsSize){
        *returnSize = 0;
        return NULL;
    }
    char** ans = malloc(sizeof(char*)*25);
    char str[25];
    int cnt = 0;
    long start = nums[0], pos = 0;
    for(long i = 1; i < numsSize; i++){
        if(nums[i] != start+i-pos){
            if(start == nums[i-1]){
                sprintf(str, "%ld", start);
            } else {
                sprintf(str, "%ld->%d", start, nums[i-1]);
            }
            ans[cnt] = malloc(strlen(str)+1);
            sprintf(ans[cnt++], "%s", str);
            start = nums[i];
            pos = i;
        }
    }
    if(start == nums[numsSize-1]){
        sprintf(str, "%ld", start);
    } else {
        sprintf(str, "%ld->%d", start, nums[numsSize-1]);
    }
    ans[cnt] = malloc(strlen(str)+1);
    sprintf(ans[cnt++], "%s", str);
    *returnSize = cnt;
    return ans;
}