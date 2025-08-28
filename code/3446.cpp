#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<int> blTriangle;
        priority_queue<int, vector<int>, greater<int>> trTriangle;
        for(int i = n-1; i >= 0; --i) {
            int col = 0, row = i;
            while(row < n && col < n){
                blTriangle.push(grid[row++][col++]);
            }
            col = 0, row = i;
            while(row < n && col < n){
                grid[row++][col++] = blTriangle.top();
                blTriangle.pop();
            }
        }
        for(int i = 1; i < n; ++i){
            int col = i, row = 0;
            while(col < n && row < n){
                trTriangle.push(grid[row++][col++]);
            }
            col = i, row = 0;
            while(col < n && row < n){
                grid[row++][col++] = trTriangle.top();
                trTriangle.pop();
            }
        }
        return grid;
    }
};