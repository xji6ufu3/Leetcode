#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int halfK = k/2;
        for(int i = 0; i < halfK; ++i){
            for(int j = 0; j < k; ++j){
                int tmp = grid[x+i][y+j];
                grid[x+i][y+j] = grid[x+k-i-1][y+j];
                grid[x+k-i-1][y+j] = tmp;
            }
        }
        return grid;
    }
};