class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int len = nums.size(), cnt = 0;
        vector<int> ans(len, 0);
        for(int i = 0; i < len-1; ++i){
            if(nums[i] && nums[i] == nums[i+1]){
                ans[cnt++] = nums[i]*2;
                ++i;
            } else if (nums[i]) {
                ans[cnt++] = nums[i];
            }
        }
        if(nums[len-1] && nums[len-2] != nums[len-1]) ans[cnt++] = nums[len-1];
        return ans;
    }
};