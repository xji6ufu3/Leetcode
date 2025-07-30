class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int themax = 0;
        for(int num : nums){
            if(themax < num){
                themax = num;
            }
        }
        int ans = 0, ptr = 0, n = nums.size();
        while(ptr < n){
            if(nums[ptr] == themax){
                int len = 0;
                while(ptr < n && nums[ptr] == themax){
                    ++len;
                    ++ptr;
                }
                if(ans < len){
                    ans = len;
                }
            } else {
                ++ptr;
            }
        }
        return ans;
    }
};