int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int findLucky(int* arr, int arrSize) {

    int lucky = -1;

    qsort(arr, arrSize, sizeof(int), cmp);

    int ptr = arr[0], cnt = 1;
    for(int i = 1; i < arrSize; i++){
        if(ptr != arr[i]){
            if(ptr == cnt){
                lucky = lucky < ptr ? ptr : lucky;
            }
            ptr = arr[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if(ptr == cnt){
        lucky = lucky < ptr ? ptr : lucky;
    }

    return lucky;
}