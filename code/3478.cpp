#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0, neg = INT_MIN;
        bool isAnyLargeZero = false, check[101] = {};
        for(int num : nums){
            if(num >= 0){
                isAnyLargeZero = true;
                if(!check[num]){
                    check[num] = true;
                    ans += num;
                }
            } else {
                neg = max(neg, num);
            }
        }
        return isAnyLargeZero ? ans : neg;
    }
};