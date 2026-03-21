#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // use DP to solve this weighted Longest Common Subsequence

        int total_ascii = 0;
        int len1 = s1.length(), len2 = s2.length();

        for(int i = 0; i < len1; ++i){
            total_ascii += (int)(s1[i]);
        }
        for(int i = 0; i < len2; ++i){
            total_ascii += (int)(s2[i]);
        }

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int p1 = 1; p1 <= len1; ++p1){
            for(int p2 = 1; p2 <= len2; ++p2){
                char c1 = s1[p1-1], c2 = s2[p2-1];
                if(c1 == c2){
                    // the previous LCS + the same char
                    dp[p1][p2] = dp[p1-1][p2-1] + (int)c1;
                } else {
                    // skip s1[p1] or s2[p2]
                    dp[p1][p2] = max(dp[p1-1][p2], dp[p1][p2-1]);
                }
            }
        }
        return total_ascii - 2 * dp[len1][len2];
    }
};