#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int n : nums) sum += n;
        return sum % k;
    }
};