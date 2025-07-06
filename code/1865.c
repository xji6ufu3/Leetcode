/**
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);
 
 * int param_2 = findSumPairsCount(obj, tot);
 
 * findSumPairsFree(obj);
*/

/**
 * nums2 做一個 hashMap，紀錄每個數字的次數
 * 每次查 tot 時，其實是對 hashMap 查 tot-nums1 的出現次數
 * 在 add 時更改 hashMap
 * 注意，雖說 nums2 < 1e5 ，但這只是初值小於 1e5 ， val 另外算
 * val 的範圍雖也是 1e5 ，但最多有 1000 次的 add ，所以 nums2 最高會超過 1e8
 * C 語言，使用 uthash 實作
 */

typedef struct {
    int key, val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFind(HashItem *obj, int key){
    HashItem *ret = NULL;
    HASH_FIND_INT(obj, &key, ret);
    return ret;
}

void hashSet(HashItem **obj, int key, int val){
    HashItem *item = hashFind(*obj, key);
    if(item){
        item->val = val;
    } else {
        HashItem *newItem = (HashItem*)malloc(sizeof(HashItem));
        newItem->key = key;
        newItem->val = val;
        HASH_ADD_INT(*obj, key, newItem);
    }
}

int hashGet(HashItem *obj, int key){
    HashItem *ret = hashFind(obj, key);
    return ret ? ret->val : 0;
}

void hashFree(HashItem **obj) {
    HashItem *current = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, current, tmp) {
        HASH_DEL(*obj, current);
        free(current);
    }
}

typedef struct {
    int *nums1, *nums2;
    int n1size, n2size;
    HashItem *cnt;
} FindSumPairs;


FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    FindSumPairs* obj = (FindSumPairs *)malloc(sizeof(FindSumPairs));
    obj->nums1 = nums1;
    obj->n1size = nums1Size;
    obj->nums2 = nums2;
    obj->n2size = nums2Size;
    obj->cnt = NULL;
    for (int i = 0; i < nums2Size; i++) {
        hashSet(&(obj->cnt), nums2[i], hashGet(obj->cnt, nums2[i]) + 1);
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {
    hashSet(&(obj->cnt), obj->nums2[index], hashGet(obj->cnt, obj->nums2[index]) - 1);
    obj->nums2[index] += val;
    hashSet(&(obj->cnt), obj->nums2[index], hashGet(obj->cnt, obj->nums2[index]) + 1);
}

int findSumPairsCount(FindSumPairs* obj, int tot) {
    int ans = 0;
    for(int i = 0; i < obj->n1size; ++i){
        ans += hashGet(obj->cnt, tot - obj->nums1[i]);
    }
    return ans;
}

void findSumPairsFree(FindSumPairs* obj) {
    hashFree(&(obj->cnt));
    free(obj);
}
