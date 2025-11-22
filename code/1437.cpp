#include <vector>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // read from right to left
        int i = nums.size() - 1;
        for(; i >= 0 && nums[i] == 0; --i);
        if(i < 0) return true;
        int last = i;
        --i;
        while(i >= 0){
            if(nums[i] == 1){
                if(last - 1 - i < k) return false;
                last = i;
            }
            --i;
        }
        return true;
    }
};