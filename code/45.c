#include <limits.h>
#include <stdio.h>

int jump(int* nums, int numsSize) {
    int cntarr[numsSize];

    cntarr[numsSize-1] = 0;

    for(int i = numsSize-2; i >= 0; --i){
        // printf("go to %d\n", i);
        int minn = INT_MAX;
        for(int j = 1; j <= nums[i]; ++j){
            if(i+j == numsSize) break;
            int currjmp = cntarr[i+j];
            if(minn > currjmp) minn = currjmp;
        }
        cntarr[i] = (minn < INT_MAX) ? minn+1 : INT_MAX;
        // printf("cntarr[%d]: %d\n", i, cntarr[i]);
    }

    return cntarr[0];
}

int main(){
    int siz;
    printf("n: ");
    scanf("%d", &siz);

    int nums[siz];
    printf("nums: ");
    for(int i = 0; i < siz; ++i){
        scanf("%d", &nums[i]);
    }

    printf("Ans: %d\n", jump(nums, siz));
}