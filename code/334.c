#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    // a < b < c
    int a = INT_MAX;
    int b = INT_MAX;

    for (int i = 0; i < numsSize; ++i){
        int x = nums[i];
        if (x <= a){
            // don't change b, b/c b means there is still a old a at it left.
            // the change of a doesn't change the b, because there is an old a at b's left hand.
            a = x;
        } else if (x <= b){
            b = x;
        } else{
            return true;
        }
    }
    return false;
}