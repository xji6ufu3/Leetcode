#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int minMoves(int* nums, int numsSize) {
    int themin = INT_MAX, ans = 0;

    for(int i = 0; i < numsSize; ++i){
        if(themin > nums[i]){
            themin = nums[i];
        }
    }
    
    for(int i = 0; i < numsSize; ++i){
        ans += nums[i] - themin;
    }

    return ans;
}

int main(){
    int size;

    printf("numsSize: ");
    scanf("%d", &size);

    int *nums = (int *)malloc(size * sizeof(int));

    printf("nums: \n");
    for(int i = 0; i < size; ++i){
        scanf("%d", &nums[i]);
    }

    int ans = minMoves(nums, size);

    printf("ans: %d\n", ans);

    return 0;
}
