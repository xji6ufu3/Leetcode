


typedef struct {
    int *sums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* n = malloc(sizeof(NumArray));
    n->sums = malloc(numsSize * sizeof(int));
    n->sums[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        n->sums[i] = n->sums[i-1] + nums[i];
    }
    return n;
}

int numArraySumRange(NumArray* n, int left, int right) {
    return left ? n->sums[right]-n->sums[left-1] : n->sums[right];
}

void numArrayFree(NumArray* n) {
    free(n->sums);
    free(n);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/