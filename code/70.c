/**
 * 斐波那契數列
 * f(n) = f(n−1) + f(n−2)
 */

int climbStairs(int n) {
    if(n == 1 || n == 2){
        return n;
    }
    int p1 = 1, p2 = 2, ret;
    for(int i = 3; i <= n; i++){
        ret = p1 + p2;
        p1 = p2;
        p2 = ret;
    }
    return ret;
}