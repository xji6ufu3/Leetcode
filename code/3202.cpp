class Solution {
public:
   int maximumLength(vector<int>& nums, int k) {
       int maxLen = 0;
       
       for (int val = 0; val < k; ++val) {
           vector<int> dp(k, 0);
           
           for (int num : nums) {
               int mod = num % k;
               int prev = (k + val - mod) % k;
               dp[mod] = dp[prev] + 1;
               maxLen = max(maxLen, dp[mod]);
           }
       }
       
       return maxLen;
   }
};