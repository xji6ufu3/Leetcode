#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // use two pointers and set
        int start = 0, end = 0, sum = 0, ans = 0;
        unordered_set<int> numset;
        for(; end < nums.size(); ++end){
            while(numset.count(nums[end])){
                numset.erase(nums[start]);
                sum -= nums[start++];
            }
            sum += nums[end];
            numset.insert(nums[end]);
            ans = max(ans, sum);
        }
        return ans;
    }
};