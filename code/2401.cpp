#include <vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // subarray: sliding  window
        int begin = 0, end = 0, subarrOR = 0, maxLen = 0;

        for(end = 0; end < nums.size(); ++end){
            while((subarrOR & nums[end]) != 0){
                // Remove leftmost element's bits
                subarrOR ^= nums[begin++];
            }
            subarrOR |= nums[end];
            maxLen = max(maxLen, end - begin + 1);
        }

        return maxLen;
    }
};