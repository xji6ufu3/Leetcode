#include <string>

using namespace std;

class Solution {
public:
    int numSub(string s) {
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