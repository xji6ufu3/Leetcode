#include <stdlib.h>

#define nSize 1000

typedef struct {
    int *pre_prod; // prefix product
    int cap;
    int len;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *ret = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    ret->cap = nSize;
    ret->len = 0;
    ret->pre_prod = (int*)malloc(nSize * sizeof(int));
    ret->pre_prod[0] = 1;
    return ret;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num == 0){
        obj->len = 0; // the num before 0, the product is 0 too.
        return;
    }
    if(obj->len + 1 == obj->cap){
        obj->pre_prod = (int*)realloc(obj->pre_prod, obj->cap * 2 * sizeof(int));
        obj->cap *= 2;
    }
    obj->pre_prod[obj->len + 1] = num * obj->pre_prod[obj->len];
    obj->len++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(k > obj->len) return 0;
    // else, the two subseqs can be all nonzero
    return obj->pre_prod[obj->len] / obj->pre_prod[obj->len-k];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->pre_prod);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
