#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int numsSize = nums.size();
        
        vector<long long> leftMin(n+2, 0);
        vector<long long> rightMax(n+2, 0);
        
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long leftSum = 0, rightSum = 0;

        for (int i = 0; i < n; ++i) {
            maxHeap.push(nums[i]);
            minHeap.push(nums[numsSize-i-1]);
            leftSum += nums[i];
            rightSum += nums[numsSize-i-1];
        }

        leftMin[0] = leftSum;
        rightMax[n+1] = rightSum;

        for(int i = n; i < 2*n; ++i){
            maxHeap.push(nums[i]);
            minHeap.push(nums[numsSize-i-1]);
            leftSum += nums[i] - maxHeap.top();
            rightSum += nums[numsSize-i-1] - minHeap.top();
            leftMin[i-n+1] = leftSum;
            rightMax[numsSize-i-n] = rightSum;
            maxHeap.pop();
            minHeap.pop();
        }

        // Find minimum difference
        long long result = LLONG_MAX;
        for (int i = n-1; i < 2*n; ++i) {
            result = min(result, leftMin[i-n+1] - rightMax[i-n+2]);
        }

        return result;
    }
};
