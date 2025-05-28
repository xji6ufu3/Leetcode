int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    long ldivid = labs((long)dividend), ldivis = labs((long)divisor);
    long mul = 0;
    while(ldivid >= ldivis){
        long tmp = ldivis;
        long tmpmul = 1;
        while(ldivid >= (tmp << 1)){
            tmp <<= 1;
            tmpmul <<= 1;
        }
        mul += tmpmul;
        ldivid -= tmp;
    }
    return (int)((dividend < 0) ^ (divisor < 0) ? -mul : mul);
}