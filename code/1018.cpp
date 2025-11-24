#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        // 不能遞迴的消除 101 子字串，因為 10100 + 101 = 11001 (25) 會進位
        int remainder = 0;
        vector<bool> ans(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            remainder = remainder * 2 + nums[i];
            remainder %= 5;
            ans[i] = remainder % 5 == 0;
        }
        return ans;
    }
};