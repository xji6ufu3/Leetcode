int singleNumber(int* nums, int numsSize) {
    // int sum = 0;
    // bool apper[6*10000] = {false};
    // for(int i = 0; i < numsSize; i++){
    //     if(apper[nums[i]+3*10000]){
    //         sum += nums[i] * (-1);
    //     } else {
    //         apper[nums[i]+3*10000] = true;
    //         sum += nums[i];
    //     }
    // }
    // return sum;

    // 因為 x XOR x = 0, x XOR 0 = x, 且有交換律 a XOR b = b XOR a
    // 所以不論怎麼排序，例如 4,1,2,1,2，做 XOR 時：4^1^2^1^2
    // 都可以用交換律重新排序為 4^(1^1)^(2^2) = 4^0 = 4
    // 抓出單獨的數字出來

    int ans = 0;
    for(int i = 0; i < numsSize; i++) ans ^= nums[i];
    return ans;
}