/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int cnt = 0;
    int* ans = malloc(sizeof(int) * (nums1Size > nums2Size ? nums1Size : nums2Size));
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int ptr1 = 0, ptr2 = 0;
    while(1){
        int now1 = nums1[ptr1], now2 = nums2[ptr2];
        if(now1 == now2){
            ans[cnt++] = now1;
            while(ptr1 < nums1Size && nums1[ptr1] == now1) ptr1++;
            while(ptr2 < nums2Size && nums2[ptr2] == now2) ptr2++;
        } else {
            if(now1 < now2){
                while(ptr1 < nums1Size && nums1[ptr1] == now1) ptr1++;
            } else {
                while(ptr2 < nums2Size && nums2[ptr2] == now2) ptr2++;
            }
        }
        if(ptr1 == nums1Size || ptr2 == nums2Size) break;
    }
    *returnSize = cnt;
    return ans;
}