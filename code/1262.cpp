#include <vector>
#include <math.h>

using namespace std;

/**
 * Brute force/BFS over all subsets is O(2^n), 
 * so use a DP approach instead.
 * or use Greedy (faster)
 */

class Solution {
public:
// Solution 1
    // // time complexity: O(3n)
    // // space complexity: O(1)
    // int maxSumDivThree(vector<int>& nums) {
    //     // dp[i] stores the best sum so far whose remainder mod 3 is i
    //     // -1 means unreachable.
    //     // Start with 0 reachable at remainder 0; other remainders are unreachable initially.
    //     vector<int> dp = {0, -1, -1};
        
    //     for (int num : nums) {
    //         vector<int> curDP = dp;
    //         for (int r = 0; r < 3; ++r) {
    //             if (curDP[r] >= 0) {
    //                 int newpos = (num + r) % 3;
    //                 dp[newpos] = max(dp[newpos], curDP[r] + num);
    //             }
    //         }
    //     }

    //     return dp[0];
    // }

// Solution 2
    // Greedy
    // sum all the numbers
    // if sum % 3 == 1:
        // 1. sum - 1 number with % 3 == 1
        // 2. sum - 2 numbers with % 3 == 2, cause (2+2)%3 == 1
    // if sum % 3 == 2:
        // 1. sum - 1 number with % 3 == 2
        // 2. sum - 2 numbers with % 3 == 1, cause (1+1)%3 == 2
    // at most 2 numbers will be removed. no more.
    // time complexity: O(n)
    // space complexity: O(1)
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> remainder1(2, INT_MAX), remainder2(2, INT_MAX);
        
        for(int n : nums){
            sum += n;
            int remainder = n % 3;
            if(remainder == 1){
                if(n < remainder1[0]){
                    remainder1[1] = remainder1[0];
                    remainder1[0] = n;
                } else if(n < remainder1[1]){
                    remainder1[1] = n;
                }
            } else if(remainder == 2){
                if(n < remainder2[0]){
                    remainder2[1] = remainder2[0];
                    remainder2[0] = n;
                } else if(n < remainder2[1]){
                    remainder2[1] = n;
                }
            }
        }

        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1){
            int sumRemainder2 = (remainder2[0] == INT_MAX || remainder2[1] == INT_MAX) ? INT_MAX : remainder2[0] + remainder2[1];
            return sum - min(remainder1[0], sumRemainder2);
        } else{ // sum % 3 == 2
            int sumRemainder1 = (remainder1[0] == INT_MAX || remainder1[1] == INT_MAX) ? INT_MAX : remainder1[0] + remainder1[1];
            return sum - min(remainder2[0], sumRemainder1);
        }
    }
};
