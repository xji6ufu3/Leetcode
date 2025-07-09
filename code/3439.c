int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int n = startTimeSize;
    int gapSize = n + 1;
    int gap[gapSize];

    gap[0] = startTime[0];
    for(int i = 0; i < n-1; ++i){
        gap[i+1] = startTime[i+1] - endTime[i];
    }
    gap[n] = eventTime - endTime[n-1];

    int winSum = 0, winSize = k+1;
    for(int i = 0; i < winSize; ++i){
        winSum += gap[i];
    }
    int maxWinSum = winSum;
    for(int i = winSize; i < gapSize; ++i){
        winSum += gap[i] - gap[i - winSize];
        if(maxWinSum < winSum) maxWinSum = winSum;
    }
    
    return maxWinSum;
}