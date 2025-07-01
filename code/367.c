bool isPerfectSquare(int num) {
    int left = 1, right = 46340;
    while(left <= right){
        int mid = left + (right - left) / 2;
        int power = mid * mid;
        if(num == power) return true;
        else if(num < power) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}