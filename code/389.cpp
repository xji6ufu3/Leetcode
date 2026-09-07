#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.length();
        int sum = t[len];
        for(int i = 0; i < len; ++i){
            sum += (int)(t[i] - s[i]);
        }
        return (char)sum;
    }
};