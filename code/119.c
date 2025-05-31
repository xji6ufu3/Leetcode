/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int* ans = malloc(sizeof(int) * (rowIndex + 1));
    ans[0] = ans[rowIndex] = 1;
    for(int i = 1; i < rowIndex; i++){
        // (long)ans[i-1] 是因為計算時可能溢出 INT，當 rowIndex >= 33
        ans[i] = (long)ans[i-1] * (rowIndex - i + 1)  / i;
    }
    return ans;
}