bool isPowerOfThree(int n) {
    if(n <= 0) return false;
    double power = log(n)/log(3);
    // check the floating point error
    return fabs(power - round(power)) < 1e-10;
}