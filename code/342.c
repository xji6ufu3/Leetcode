bool isPowerOfFour(int n) {
    /*
    if(n <= 0) return false;
    double power = log2(n);
    int r = round(power);
    if(fabs(power - r) >= 1e-10) return false;
    if(r%2) return false;
    return true;
    */

    // n > 0
    // n 是 2 的次方 (只有一個 bit 為 1)
    // 且這唯一一個 1 的 bit 在奇數位 (1、4、16...)

    return (n > 0) && ((n & (n-1)) == 0) && (n & 0b01010101010101010101010101010101);
}