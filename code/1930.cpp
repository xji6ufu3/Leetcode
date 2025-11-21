#include <string>
#include <vector>

using namespace std;

class Solution {
public:    
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        int ans = 0;

        for(int i = 0; i < s.length(); ++i){
            int c = s[i] - 'a';
            if(first[c] == -1){
                first[c] = i;
            }
            last[c] = i;
        }
        
        // choose the first and third letter
        for(int i = 0; i < 26; ++i){
            if(first[i] != -1 && last[i] - first[i] >= 2){
                vector<bool> mid(26, 0);
                int cnt = 0;
                // count the non-repeated letter between first and last letter
                for(int j = first[i]+1; j < last[i]; ++j){
                    int c = s[j] - 'a';
                    if(!mid[c]){
                        ++cnt;
                        mid[c] = true;
                    }
                    // early stopping
                    if(cnt == 26) break;
                }
                ans += cnt;
            }
        }

        return ans;
    }
};