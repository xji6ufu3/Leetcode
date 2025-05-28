/*
這裡將 numsSize 稱為 size
從右往左找，找到第一個遞減對，也就是找到 nums[i-1] < nums[i] for i--
也就是 nums[i] < nums[i+1] for i=size-1-1, i--
則 nums[i] 就是要找的數，也代表 nums[i+1] ~ nums[size-1] 是最大排序 (由左而右的非嚴格遞減)
要從 nums[i+1] ~ nums[size-1] 找出比 nums[i] 大且最接近 nums[i] 且最靠右的數字。
也就是由左而右找到剛好比 nums[i] 小的數，假設是 nums[m]，則要找的數字是 nums[m-1]
將 nums[i] 與 nums[m-1] 交換位置 (i < m-1)
之後，還需要將 nums[i+1] ~ num[size-1] 重新排列改為由左而右的非嚴格遞增，這樣整體才會是下一個最小的字典序
因為  nums[i+1] ~ nums[size-1] 已經是由左而右的非嚴格遞減了，所以只要將這串數列翻轉即可
如果找不到 i，代表全部都是由右而左的非嚴格遞增，也就是由左而右的非嚴格遞減，也就是最大排列，則倒序輸出就是最小排列
*/ 

void swap(int* nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    printf("swap %d, %d\n", i, j);
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 1 - 1;
    for(; i >= 0 && nums[i] >= nums[i+1]; i--);
    if(i == -1){
        for(int j = 0; j < numsSize/2; j++){
            swap(nums, j, numsSize-1-j);
        }
        return;
    }
    int j = i + 1 + 1;
    for(; j < numsSize && nums[j] > nums[i]; j++);
    swap(nums, i, j-1);
    for(j = numsSize - 1, ++i; i < j; i++, j--){
        swap(nums, i, j);
    }
}