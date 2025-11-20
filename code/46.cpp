#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> used;
    vector<vector<int>> ans;
    vector<int> premutation;

    void dfs(vector<int>& nums){
        if(premutation.size() == nums.size()){
            ans.push_back(premutation);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                used[i] = true;
                premutation.push_back(nums[i]);
                dfs(nums);

                // backtracking
                used[i] = false;
                premutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        dfs(nums);
        return ans;
    }
};