int maxProfit(int* prices, int pricesSize) {
    int maxP = 0, minP = prices[0];
    for(int i = 0; i < pricesSize; i++){
        if(minP > prices[i]) minP = prices[i];
        if(maxP < prices[i] - minP) maxP = prices[i] - minP;
    }
    return maxP;
}