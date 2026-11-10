#include <limits.h>

int climbStairs(int n, int* costs, int costsSize) {
    int dp[n+1]; // minimum cost to reach step

    for(int i = 0; i < n+1; ++i){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        dp[i+1] = dp[i+1] < dp[i] + costs[i] + 1 ? dp[i+1] : dp[i] + costs[i] + 1;
        if(i + 2 <= n){
            dp[i+2] = dp[i+2] < dp[i] + costs[i+1] + 4 ? dp[i+2] : dp[i] + costs[i+1] + 4;
        }
        if(i + 3 <= n){
            dp[i+3] = dp[i+3] < dp[i] + costs[i+2] + 9 ? dp[i+3] : dp[i] + costs[i+2] + 9;
        }
    }

    return dp[n];
}
