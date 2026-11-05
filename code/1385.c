#define RANGE 2001
#define SHIFT 1000

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int numSum[RANGE] = {0}, cnt = 0, ans = 0;

    for(int i = 0; i < arr2Size; ++i){
        numSum[arr2[i] + SHIFT] = 1;
    }

    for(int i = 0; i < RANGE; ++i){
        if(numSum[i]){
            cnt += numSum[i];
        }
        numSum[i] = cnt;
    }

    for(int i = 0; i < arr1Size; ++i){
        int right = arr1[i] + SHIFT + d, left = arr1[i] + SHIFT - d - 1;
        if(right >= RANGE) right = RANGE - 1;
        if(left < 0) left = 0;

        if(numSum[right] - numSum[left] == 0){
            ++ans;
        }
    }

    return ans;
}
