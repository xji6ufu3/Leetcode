/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void findsum(int* nums, int ptr, int size, int target, int* retsize, int** retcol, int*** ans, int* cap, int* record, int len){
    for(int i = ptr; i < size; i++){
        // 當前的 nums[i] 跟前一個一樣時，就跳過這個 nums[i]，以避免重複組合
        if(i > ptr && nums[i] == nums[i - 1]) continue;
        if(nums[i] > target) return;
        record[len] = nums[i];
        if(nums[i] == target){
            len++;
            int pos = *retsize;
            // O(n^2) 的檢查方式會導致 TLE
            // for(int j = 0; j < pos; j++){
            //     int same = 1, limit = (*retcol)[j];
            //     limit = limit > len ? len : limit;
            //     for(int k = 0; k < limit; k++){
            //         if((*ans)[j][k] != record[k]){
            //             same = 0;
            //             break;
            //         }
            //     }
            //     if(same) return;
            // }
            if(pos+1 > *cap){
                *ans = (int**)realloc(*ans, sizeof(int*)*(*cap)*2);
                *retcol = (int*)realloc(*retcol, sizeof(int)*(*cap)*2);
                if(*ans && *retcol) (*cap) *= 2;
                else printf("error\n");
            }
            (*ans)[pos] = malloc(sizeof(int)*len);
            *retsize += 1;
            for(int j = 0; j < len; j++){
                (*ans)[pos][j] = record[j];
            }
            (*retcol)[pos] = len;
            break;
        } else {
            findsum(nums, i+1, size, target-nums[i], retsize, retcol, ans, cap, record, len+1);
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    int cap = 256;
    int** ans = malloc(sizeof(int*)*cap);
    *returnColumnSizes = malloc(sizeof(int*)*cap);
    int record[105];
    findsum(candidates, 0, candidatesSize, target, returnSize, returnColumnSizes, &ans, &cap, record, 0);
    return ans;
}