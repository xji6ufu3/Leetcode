#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int res = INT_MAX, sum = 0;

    int calc(int part1, int part2, int part3) {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();  // n nodes
        vector<vector<int>> adjacencyList(n); // initialize n vector<int> space

        for (auto &v : edges){ // build adjacency list
            adjacencyList[v[0]].push_back(v[1]);
            adjacencyList[v[1]].push_back(v[0]);
        }

        for (int x : nums) { // total XOR value of tree
            sum ^= x;
        }

        dfs(0, -1, nums, adjacencyList);
        return res;
    }

    int dfs(int node1, int parent, vector<int> &nums,  vector<vector<int>> &adjacencyList){
        int son = nums[node1];

        for (auto &child : adjacencyList[node1]) {
            if (child != parent) {
                son ^= dfs(child, node1, nums, adjacencyList);
            }
        }

        if(find(adjacencyList[node1].begin(), adjacencyList[node1].end(), parent) != adjacencyList[node1].end()){
            dfs2(parent, node1, son, node1, nums, adjacencyList);
        }

        return son;
    }

    int dfs2(int node2, int parent, int firstXORsum, int firstTreeRoot, vector<int> &nums, vector<vector<int>> &adjacencyList){
        int son = nums[node2];

        for (auto &child : adjacencyList[node2]) {
            if (child != parent) {
                son ^= dfs2(child, node2, firstXORsum, firstTreeRoot, nums, adjacencyList);
            }
        }

        if (parent == firstTreeRoot) {
            return son;
        }

        res = min(res, calc(firstXORsum, son, sum ^ firstXORsum ^ son));

        return son;
    }
};