#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string higher = x > y ? "ab" : "ba";
        string lower = x > y ? "ba" : "ab";

        int ans = removeStr(s, higher, max(x,y)) + removeStr(s, lower, min(x,y));

        return ans;
    }
    int removeStr(string& s, string& pair, int score){
        stack<char> charStack;
        int sum = 0;
        for(char c : s){
            if(!charStack.empty() && charStack.top() == pair[0] && c == pair[1]){
                charStack.pop();
                sum += score;
            } else {
                charStack.push(c);
            }
        }
        s.clear();
        while(!charStack.empty()){
            s += charStack.top();
            charStack.pop();
        }
        reverse(s.begin(), s.end());
        return sum;
    }
};