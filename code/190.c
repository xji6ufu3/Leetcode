uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, cnt = 0;
    while(n){
        ans <<= 1;
        ans += n%2;
        n >>= 1;
        cnt++;
    }
    for(; cnt < 32; cnt++) ans <<= 1;
    return ans;
}