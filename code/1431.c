#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *results = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;
    int themax = INT_MIN;

    for(int i = 0; i < candiesSize; ++i){
        if(themax < candies[i]){
            themax = candies[i];
        }
    }

    for(int i = 0; i < candiesSize; ++i){
        results[i] = candies[i] + extraCandies >= themax;
    }

    return results;
}
