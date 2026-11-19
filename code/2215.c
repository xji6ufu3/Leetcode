#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    *returnSize = 2;

    int **ans = (int**)malloc(2 * sizeof(int*));
    ans[0] = (int*)malloc(nums1Size * sizeof(int));
    ans[1] = (int*)malloc(nums2Size * sizeof(int));

    int cnt1 = 0, cnt2 = 0;
    int ptr1 = 0, ptr2 = 0;

    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    for(ptr1 = 0,  ptr2 = 0; ptr1 < nums1Size;){
        while(ptr2 < nums2Size && nums2[ptr2] < nums1[ptr1]){
            ++ptr2;
        }

        if(!(ptr2 < nums2Size) || nums1[ptr1] != nums2[ptr2]){
            ans[0][cnt1++] = nums1[ptr1];
        }

        while(++ptr1 < nums1Size && nums1[ptr1] == nums1[ptr1-1]);
    }

    for(ptr1 = 0,  ptr2 = 0; ptr2 < nums2Size;){
        while(ptr1 < nums1Size && nums1[ptr1] < nums2[ptr2]){
            ++ptr1;
        }

        if(!(ptr1 < nums1Size) || nums2[ptr2] != nums1[ptr1]){
            ans[1][cnt2++] = nums2[ptr2];
        }

        while(++ptr2 < nums2Size && nums2[ptr2] == nums2[ptr2-1]);
    }

    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = cnt1;
    (*returnColumnSizes)[1] = cnt2;

    return ans;
}
