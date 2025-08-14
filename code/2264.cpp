#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char best = 0;
        for (int i = 0; i + 2 < (int)num.size(); ++i) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (num[i] > best) best = num[i];
            }
        }
        return best ? string(3, best) : "";
    }
};
