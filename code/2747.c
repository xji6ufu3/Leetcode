#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int logcmp(const void **a, const void **b){
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int* countServers(int n, int** logs, int logsSize, int* logsColSize, int x, int* queries, int queriesSize, int* returnSize) {
    int *arr = (int*)malloc(queriesSize * sizeof(int));
    int ptr1 = 0, ptr2 = 0;
    int status[n] = {};

    status[logs[ptr1][0]]++;

    qsort(logs, logsSize, sizeof(int*), logcmp);
    qsort(queries, queriesSize, sizeof(int), cmp);

    for(int i = 0; i < queriesSize; ++i){
        int start = queries[i] - x, end = queries[i];
        
        while(ptr2 < logsSize && logs[ptr2][1] <= end){ // queue push
            ++ptr2;
            if(ptr2 < logsSize){
                status[logs[ptr2][0]]++;
            }
        }
        --ptr2;

        while(ptr1 < logsSize && logs[ptr1][1] < start){ // queue pop
            ++ptr1;
            if(ptr1 < logsSize){
                status[logs[ptr1][0]]--;
            }
        }
        
    }  
    
    return arr;
}