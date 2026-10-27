#include <stdio.h>

int jump(int* nums, int numsSize) {
    int retjmp = 0, rptr = 0, lptr = 0;
    while(lptr <= rptr && rptr < numsSize-1){
        ++retjmp;
        int newrptr = rptr;
        for(int i = lptr; i <= rptr; ++i){
            newrptr = i+nums[i] > newrptr ? i+nums[i] : newrptr;
        }
        lptr = rptr + 1;
        rptr = newrptr;
    }
    if(rptr >= numsSize-1){
        return retjmp;
    }
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