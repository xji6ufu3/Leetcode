double findMaxAverage(int* nums, int numsSize, int k) {
    long long maxSum = 0, sum;
    
    for(int i = 0; i < k; ++i){
        maxSum += nums[i]; 
    }

    sum = maxSum;

    for(int i = k; i < numsSize; ++i){
        sum += nums[i] - nums[i-k];
        maxSum = maxSum > sum ? maxSum : sum;
    }

    return (double)maxSum / k;
}
