int getGCD(int a, int b){
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }

    return a;
}

int maxLength(int* nums, int numsSize) {
    int window_size = numsSize;

    for(bool state = false; window_size >= 3; --window_size){
        for(int i = 0; i+window_size-1 < numsSize; ++i){
            int gcd = nums[i], lcm = nums[i], x = 1;

            for(int j = i+1; j < numsSize && j-i < window_size; ++j){
                gcd = getGCD(gcd, nums[j]);
            }

            for(int j = i+1; j < numsSize && j-i < window_size; ++j){
                int x_gcd = getGCD(lcm, nums[j]);
                x *= x_gcd;
                lcm *= nums[j] / x_gcd;
                if(gcd % x || x > gcd) break;
            }

            state = x == gcd;
            if(state) break;
        }

        if(state) break;
    }

    return window_size;
}
