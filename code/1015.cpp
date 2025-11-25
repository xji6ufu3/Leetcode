#include <vector>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 1, cnt = 0;
        vector<bool> bit(k, false);
        while(true){
            ++cnt;
            int remainder = n % k;
            if(remainder == 0) return cnt;
            else if(bit[remainder] == false){
                bit[remainder] = true;
                n = remainder * 10 + 1;
            } else {
                return -1;
            }
        }
    }
};