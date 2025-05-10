int reverse(int x) {
    int reversed = 0;

    while (x) {
        int lastDigit = x % 10;
        x /= 10;

        // 2^31 - 1 = 2147483647
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && lastDigit > 7)) {
            return 0;
        }

        // -2^31 = -2147483648
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && lastDigit < -8)) {
            return 0;
        }

        reversed = reversed * 10 + lastDigit;
    }

    return reversed;
}