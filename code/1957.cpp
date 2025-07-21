class Solution {
public:
    string makeFancyString(string s) {
        // s.erase() is an O(n) operation.
        // Using it inside a loop can lead to worst-case time complexity of O(n^2).
        int len = s.size(), valid = 0;
        for(int i = 0; i < len-2; ++i){
            if(s[i] == s[i+1] && s[i] == s[i+2]){
                while(i+2 < len && s[i] == s[i+2]){
                    ++i;
                }
            }
            if(i+2 < len) s[valid++] = s[i];
        }
        if(len-2 >= 0)
            s[valid++] = s[len-2];
        if(len-1 >= 0)
            s[valid++] = s[len-1];
        return s.substr(0,valid);
    }
};