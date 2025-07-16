class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        int count_even = 0, count_odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) count_even++;
            else count_odd++;
        }

        auto alt_parity = [&](int start) {
            int count = 0, expected = start;
            for (int num : nums) {
                if (num % 2 == expected) {
                    count++;
                    expected ^= 1;
                }
            }
            return count;
        };

        return std::max({count_even, count_odd, alt_parity(0), alt_parity(1)});
    }
};
