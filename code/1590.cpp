#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int r = 0;
        for(int num : nums){
            r = (r + num) % p;
        }
        if(r == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0, ans = 0;

        for(int i = 0; i < nums.size(); ++i){
            prefix = (prefix + nums[i]) % p;
            // remove subarray (j, i-1)
            // (prefix[i] - prefix[j]) % p = r
            // so, prefix[j] % p == need == (prefix[i] - r + p) % p
            // +p to prevent need < 0
            int need = (prefix - r + p) % p;
            if(mp.count(need)){
                ans = min(ans, i - mp[need]);
            }
            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};