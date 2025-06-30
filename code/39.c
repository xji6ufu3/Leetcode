/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void findsum(int* nums, int ptr, int size, int target, int *cnt, int *col, int **ans, int record[], int len){
    for(int i = ptr; i < size; i++){
        if(nums[i] > target){
            return;
        }
        if(nums[i] == target){
            col[*cnt] = len+1;
            ans[*cnt] = malloc(sizeof(int)*(len+1));
            for(int j = 0; j < len; j++){
                ans[*cnt][j] = record[j];
            }
            ans[*cnt][len] = nums[i];
            (*cnt)++;
        } else {
            record[len] = nums[i];
            findsum(nums, i, size, target - nums[i], cnt, col, ans, record, len+1);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int **ans = malloc(sizeof(int*)*155), record[35], len = 0;
    *returnColumnSizes = malloc(sizeof(int)*155);
    *returnSize = 0;
    findsum(candidates, 0, candidatesSize, target, returnSize, *returnColumnSizes, ans, record, len);
    return ans;
}