#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // Square Root Decomposition

        int n = baskets.size();
        int sqrtN = sqrt(n);
        int sectionLen = sqrtN;
        // 補齊至整數，例如當 n = 10, sqrtN = 3
        // section 數量不為 n / sqrtN = 3
        // 而是先加上 sqrtN-1 再去除，相當於對商做 ceil
        // 但如果直接寫 ceil，就要先轉成 double，而這寫法更方便，不用轉型
        int sectionNum = (n + sqrtN - 1) / sqrtN;
        int remain = 0;
        vector<int> maxSec(sectionNum);

        for(int i = 0; i < n; ++i){
            int section = i / sqrtN;
            maxSec[section] = max(maxSec[section], baskets[i]);
        }

        for(int fruit : fruits){
            for(int section = 0; section < sectionNum; ++section){
                if(maxSec[section] < fruit) continue;
                else{
                    int maxval = 0;
                    for(int i = 0, pos, pick = 0; i < sectionLen; ++i){
                        pos = section * sectionLen + i;
                        if(!(pos < n)) break;
                        if(!pick && baskets[pos] >= fruit){
                            pick = 1;
                            baskets[pos] = 0;
                        }
                        // 更新最大值
                        maxval = max(maxval, baskets[pos]);
                    }
                    maxSec[section] =  maxval;
                }
                --remain;
                break;
            }
            ++remain;
        }
        return remain;
    }
};