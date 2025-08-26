#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(37, 0); // 0 ~ 9*4 = 37
        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            cnt[sum]++;
        }
        int maxCnt = *max_element(cnt.begin(), cnt.end());
        return count(cnt.begin(), cnt.end(), maxCnt);   
    }
};