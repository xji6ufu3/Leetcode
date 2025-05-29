/*
二分搜，範圍為 1~2^16
*/

int mySqrt(int x) {
    if(x == 0 || x == 1) return x;
    if(x == 2 || x == 3) return 1;
    int l = 1, r = 1 << 16;
    while(l <= r){
        long mid = (l + r) / 2;
        if(mid*mid <= x && x < (mid+1)*(mid+1)) return (int)mid;
        else if(x < mid*mid) r = mid-1;
        else l = mid+1;
    }
    return -1;
}
