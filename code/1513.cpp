#include <string>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        // 11 -> 2*'1' + 1*'11' = 2+1
        // 111 -> 3*'1' + 2*'11' + 1*'111' = 3+2+1
        // 1111 -> 4*'1' + 3*'11' + 2*'111' + 1*'1111' = 4*3*2*1
        // so, if there is n 1's
        // the number of substrings with only 1's is n*(n+1) / 2
        long long ans = 0, cnt = 0, MOD = 1e9 + 7;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '1'){
                ++cnt;
            } else if(cnt != 0){
                ans = (ans + cnt * (cnt + 1) / 2) % MOD;
                cnt = 0;
            }
        }
        if(cnt != 0){
            ans = (ans + cnt * (cnt + 1) / 2) % MOD;
        }
        return ans;
    }
};