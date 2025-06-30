/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *ans = malloc(sizeof(int)*(n+1));
    *returnSize = n+1;
    ans[0] = 0;
    // 高位 1 ~ n-1 位的這個數字的 bits 數已知，只要確認地 n 位是否為 1
    for(int i = 1; i <= n; i++){
        ans[i] = ans[i>>1] + i%2;
    }
    return ans;
}