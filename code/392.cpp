#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size(), sptr = 0, tlen = t.size();
        for(int i = 0; i < tlen; ++i){
            if(t[i] == s[sptr]){
                ++sptr;
            }
        }
        return sptr == slen;
    }
};