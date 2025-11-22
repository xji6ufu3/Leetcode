#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // start from the beginning
        int size = bits.size(), i = 0;
        bool ans = false;
        while(i < size){
            ans = bits[i] == 0;
            ++i;
            if(!ans) ++i;
        }
        return ans;
    }
};