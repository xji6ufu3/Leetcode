class Solution {
public:
    int countOdds(int low, int high) {
        int num = high - low + 1;
        return num/2 + ((num%2) && (low%2));
    }
};