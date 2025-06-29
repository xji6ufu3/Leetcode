bool isPowerOfTwo(int n) {
    // n<=0 : false
    // 2^n: 100000...0
    // 2^n -1 : 0111...1
    // 2^n & 2^n -1 : 0
    return n > 0 && (n & (n - 1)) == 0; 
}