struct pair{
    int loc;
    int val;
};

int cmp1(const void* a, const void* b){
    return ((struct pair*)a)->val - ((struct pair*)b)->val;
}

int cmp2(const void* a, const void* b){
    return ((struct pair*)a)->loc - ((struct pair*)b)->loc;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct pair p[numsSize];
    for(int i = 0; i < numsSize; i++){
        p[i].loc = i;
        p[i].val = nums[i];
    }
    qsort(p, numsSize, sizeof(struct pair), cmp1);
    int begin = 0, val = p[0].val;
    for(int i = 1; i < numsSize; i++){
        if(p[i].val != val){
            qsort(&p[begin], i-begin, sizeof(struct pair), cmp2);
            if(i-begin > 1){
                for(int j = begin; j < i-1; j++){
                    if(abs(p[j].loc - p[j+1].loc) <= k) return true;
                }
            }
            begin = i;
            val = p[i].val;
        }
    }
    qsort(&p[begin], numsSize-begin, sizeof(struct pair), cmp2);
    if(numsSize-begin > 1){
        for(int j = begin; j < numsSize-1; j++){
            if(abs(p[j].loc - p[j+1].loc) <= k) return true;
        }
    }
    return false;
}