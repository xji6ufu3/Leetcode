#include <vector>
#include <iostream>

using namespace std;

#define DEBUG 0

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len = nums.size(), maxOR = 0, val = 0, ptr;
        vector<int> totalBitCnt(31, 0), nowBitCnt(31, 0), ans(len, 0);

        for(int num : nums){
            maxOR |= num;
            int bit = 0;
            while(num){
                totalBitCnt[bit++] += num & 1;
                num >>= 1;
            }
        }

        for(ptr = 0; ptr < len; ++ptr){
            val |= nums[ptr];
            int num = nums[ptr], bit = 0;
            while(num){
                nowBitCnt[bit++] += num & 1;
                num >>= 1;
            }
            if(val == maxOR) break;
        }

        ans[0] = ptr+1;

        if(DEBUG) cout << "maxOR: " << maxOR << '\n'; 

        for(int i = 1; i < len; ++i){
            if(ptr < i){
                fill(nowBitCnt.begin(), nowBitCnt.end(), 0);
                val = nums[i];
                ptr = i;
                int num = nums[i], bit = 0;
                while(num){
                    nowBitCnt[bit] += num & 1;
                    ++bit;
                    num >>= 1;
                }
                num = nums[i-1], bit = 0;
                while(num){
                    if(num & 1){
                        if(totalBitCnt[bit] == 1){
                            maxOR &= ~(1 << bit);
                        }
                        --totalBitCnt[bit];
                    }
                    ++bit;
                    num >>= 1;
                }
                if(DEBUG){
                    cout << "move ptr to " << ptr << ", val: " << val << '\n';
                }
            } else {
                int num = nums[i-1], bit = 0;
                while(num){
                    if(num & 1){
                        if(nowBitCnt[bit] == 1){
                            val &= ~(1 << bit);
                            if(totalBitCnt[bit] == 1){
                                maxOR &= ~(1 << bit);
                            }
                        }
                        --nowBitCnt[bit];
                        --totalBitCnt[bit];
                    }
                    ++bit;
                    num >>= 1;
                }
            }
            if(DEBUG)
                cout << "i: " << i << ", val: " << val << ", maxOR: " << maxOR << '\n';
            while(val != maxOR){
                ++ptr;
                val |= nums[ptr];
                int num = nums[ptr], bit = 0;
                while(num){
                    nowBitCnt[bit++] += num & 1;
                    num >>= 1;
                }
            }
            ans[i] = ptr - i + 1;
        }

        return ans;
    }
};