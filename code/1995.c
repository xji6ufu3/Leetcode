int countQuadruplets(int* nums, int numsSize) {
    // nums[a] + nums[b] == nums[d] - nums[c]
    
    int dcHash[101], aHash[101], ans = 0;

    for(int i = 0; i < 101; ++i){
        dcHash[i] = aHash[i] = 0;
    }

    aHash[nums[0]]++;

    for(int c = 2; c < numsSize-1; ++c){
        for(int d = c+1; d < numsSize; ++d){
            int dc = nums[d] - nums[c];

            if(dc >= 2){
                dcHash[dc]++;
            }
        }
    }

    for(int b = 1, a = 0; b < numsSize-2 && a< numsSize-3; ++b, ++a){
        for(int d = b+1, c = b; b > 1 && d < numsSize; ++d){
            int dc = nums[d] - nums[c];
            if(dc >= 2){
                dcHash[dc]--;
            }
        }

        for(int aa = 100; aa; --aa){
            if(aHash[aa] && aa + nums[b] <= 100){
                ans += aHash[aa] * dcHash[aa + nums[b]];
            }
        }

        aHash[nums[b]]++;
    }

    return ans;
}
