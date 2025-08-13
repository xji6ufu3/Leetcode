class Solution {
public:
    bool isPowerOfThree(int n) {
        return n >= 1 && 1162261467 % n == 0; // 1162261467 is 3^19, 3^19 & n should be an integer
    }
};