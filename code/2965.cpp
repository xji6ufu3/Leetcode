class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // maxSum == (2500+1)*2500/2 == 3126250 < INT_MAX
        // diff == (x-y)*n/2, can know (x-y)
        // x^2 - y^2 == (x+y)(x-y)
        // sum(n^2) = (n)(n+1)(2n+1)/6 <= 2500*2501*5001/6 == 5209375000 > INT_MAX

        int n = grid.size();
        n *= n;
        int sum = 0, nTotal = (n+1)*n/2;
        long long n2Total = 1LL*n*(n+1)*(2*n+1)/6, sum2 = 0;
        for(auto& nums : grid){
            for(auto& num : nums){
                sum += num;
                sum2 += num * num;
            }
        }
        int xMinusY = sum-nTotal;
        int xPlusY = (sum2-n2Total)/xMinusY;
        return {(xPlusY+xMinusY)/2, (xPlusY-xMinusY)/2};
    }
};