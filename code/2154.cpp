#include <vector>
#include <algorithm>
// #include <unordered_set>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == original) original *= 2;
        }
        return original;
    }
    // int findFinalValue(vector<int>& nums, int original) {
    //     unordered_set<int> s(nums.begin(), nums.end());
    //     while(s.count(original)) original *= 2;
    //     return original;
    // }
};