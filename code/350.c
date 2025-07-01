/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans = malloc(sizeof(int)*64), cap = 64, cnt = 0;
    int repeat[1005] = {0};
    for(int i = 0; i < nums1Size; i++) repeat[nums1[i]]++;
    for(int i = 0; i < nums2Size; i++){
        if(repeat[nums2[i]]){
            repeat[nums2[i]]--;
            if(cnt+1 > cap){
                ans = realloc(ans, sizeof(int) * cap*2);
                cap *= 2;
            }
            ans[cnt++] = nums2[i];
        }
    }
    *returnSize = cnt;
    return ans;
}