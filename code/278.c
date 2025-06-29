// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    // all the versions after a bad version are also bad
    int left = 1, right = n;
    while(left < right){
        int mid = left + (right-left)/2;
        if(isBadVersion(mid)){
            right = mid;  // until touch the first bad version
        } else {
            left = mid+1; // until touch the last good version
        }
    }
    return right;
}