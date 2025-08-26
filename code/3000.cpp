#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;
        int bestArea = 0;
        for (auto &d : dimensions) {
            int l = d[0], w = d[1];
            int diag = l * l + w * w;
            int area = l * w;
            if (diag > maxDiag) {
                maxDiag = diag;
                bestArea = area;
            } else if (diag == maxDiag && area > bestArea) {
                bestArea = area;
            }
        }
        return bestArea;
    }
};

