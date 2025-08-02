#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for(int cost : basket1) freq[cost]++;
        for(int cost : basket2) freq[cost]--;

        vector<int> excess;  // fruits that need to be swapped out from either basket1 or basket2
        long long minCost = 0;

        for(auto &[cost, diff] : freq){
            if(diff % 2) return -1;
            int half = abs(diff) / 2;
            for(int i = 0; i < half; ++i) excess.push_back(cost);
        }

        if (excess.empty()) return 0;

        // we can use the minimum cost fruit as an intermediate to reduce swap cost
        // like when swap 100 and 50, swap(100,50) = 50, but swap(100,1) + swap(1,50) = 1+1 = 2
        // the cost is min_val * 2
        int min_val = *min_element(basket1.begin(), basket1.end());
        min_val = min(min_val, *min_element(basket2.begin(), basket2.end()));

        sort(excess.begin(), excess.end());  // for best match (swap(smallest, biggest) = smallest)

        for (int i = 0; i < excess.size() / 2; ++i) {
            minCost += min((long long)excess[i], (long long)2 * min_val);
        }

        return minCost;
    }
};
