#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int len = nums.size(), left = 0;
        vector<bool> mark(len, false);

        for (int i = 0; i < len; ++i) {
            if (nums[i] == key) {
                int start = max(left, i - k);
                int end = min(len - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    mark[j] = true;
                }
                left = end+1;
            }
        }

        vector<int> ans;
        for (int i = 0; i < len; ++i) {
            if (mark[i]) ans.push_back(i);
        }

        return ans;
    }
};
