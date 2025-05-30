/**
 * 由右往左、由大而小的用雙指標重新排序
 * 因為 nums1 有足夠的空間 m + n，所以把兩指標指向的最大的數直接放入 nums1 即可
 * 一直比較到 nums2 全部放入 nums1 後即是答案
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    m--, n--;
    int place = nums1Size - 1;
    while(n >= 0 && m >= 0){
        nums1[place--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--]; 
    }
    while(n >= 0){
        nums1[place--] = nums2[n--];
    }
}