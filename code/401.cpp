#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void comb(int turnedOn, int &arr, int position, vector<string> &ans){
        if(turnedOn == 0){
            int hr = arr / 64, min = arr % 64;
            if(hr > 11 || min > 59) return;
            string tmp;
            tmp.reserve(6);
            if(hr > 9) tmp += '1';
            tmp += (char)((hr % 10) + '0');
            tmp += ':';
            tmp += (char)((min / 10) + '0');
            tmp += (char)((min % 10) + '0');
            ans.push_back(tmp);
            return;
        }
        if(position == 10) return;
        arr |= 1 << position;
        comb(turnedOn-1, arr, position+1, ans);
        arr ^= 1 << position;
        comb(turnedOn, arr, position+1, ans);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        int arr = 0;
        vector<string> ans;
        comb(turnedOn, arr, 0, ans);
        return ans;
    }
};