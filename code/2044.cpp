#include <vector>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, len = nums.size();
        for(int num : nums){
            maxOR |= num;
        }

        int kinds = (1 << len) - 1, ans = 0;
        for(int choose = 1; choose <= kinds; ++choose){
            int val = 0;
            for(int i = 0; i < len; ++i){
                if((choose >> i) & 1){
                    val |= nums[i];
                }
            }
            if(val == maxOR){
                ++ans;
            }
        }
        
        return ans;
    }
};