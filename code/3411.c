long long getGCD(long long a, long long b){
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }

    return a;
}

long long x(int *nums, int start, int end){
    long long prod = 1, cnt = nums[start];

    for(int i = start+1; i < end; ++i){
        long long gcd = getGCD(cnt, nums[i]);
        prod *= gcd;
        cnt *= nums[i] / gcd;
    }

    return prod;
}

int maxLength(int* nums, int numsSize) {
    
}
