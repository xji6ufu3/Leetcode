class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        /* |n[i]-n[j]| == k */
        /* n[j] == n[i] - k || n[i] + k */
        vector<int> cnt(100, 0);
        int ans = 0;
        for(auto i: nums){
            ans += i-k >= 1 ? cnt[i-k-1] : 0;
            ans += i+k <= 100 ? cnt[i+k-1] : 0;
            cnt[i-1]++;
        }
        return ans;
    }
};