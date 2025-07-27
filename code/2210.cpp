#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int sum = 0, len = nums.size();
        for(int i = 1; i < len-1; ++i){
            if(nums[i] == nums[i-1]) continue;
            else if(nums[i] == nums[i+1]){
                int right = i+1;
                while(right < len && nums[right] == nums[i]) ++right;
                if(right == len) continue;
                sum += nums[i-1] < nums[i] && nums[right] < nums[i] || nums[i-1] > nums[i] && nums[right] > nums[i];
            } else {
                sum += nums[i-1] < nums[i] && nums[i+1] < nums[i] || nums[i-1] > nums[i] && nums[i+1] > nums[i];
            }
        }
        return sum;
    }
};