#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define debug(...) do { if(debug_on) { fprintf(stderr, "[debug] " __VA_ARGS__); }} while(0)

static int debug_on = 0;

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int logcmp(const void *a, const void *b){
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int* countServers(int n, int** logs, int logsSize, int* logsColSize, int x, int* queries, int queriesSize, int* returnSize) {
    int *arr = (int*)malloc(queriesSize * sizeof(int));
    int ptr1 = 0, ptr2 = 0;
    int status[n];
    int **Q = (int **)malloc(queriesSize * sizeof(int *));

    *returnSize = queriesSize;

    for(int i = 0; i < n; ++i){
        status[i] = 0;
    }

    for(int i = 0; i < queriesSize; ++i){
        Q[i] = (int *)malloc(2 * sizeof(int));
        Q[i][0] = i;
        Q[i][1] = queries[i];
    }

    qsort(logs, logsSize, sizeof(int*), logcmp);
    qsort(Q, queriesSize, sizeof(int*), logcmp);

    for(int i = 0; i < queriesSize; ++i){
        int id = Q[i][0];
        int start = Q[i][1] - x, end = Q[i][1], cnt = i == 0 ? n : arr[Q[i-1][0]];
        debug("query: %d, start: %d, end: %d\n", id, start, end);
        
        while(ptr2 < logsSize && logs[ptr2][1] <= end){ // queue push
            if(status[logs[ptr2][0]-1] == 0){
                --cnt;
            }
            status[logs[ptr2][0]-1]++;
            debug("queue push: id: %d, time: %d\n", logs[ptr2][0], logs[ptr2][1]);
            debug("ptr2: %d, status[logs[%d][0]-1]: %d\n", ptr2, ptr2, status[logs[ptr2][0]-1]);
            ++ptr2;
        }

        while(ptr1 < logsSize && logs[ptr1][1] < start){ // queue pop
            status[logs[ptr1][0]-1]--;
            if(status[logs[ptr1][0]-1] == 0){
                ++cnt;
                debug("queue pop: id: %d, time: %d\n", logs[ptr1][0], logs[ptr1][1]);
            }
            ++ptr1;
        }

        debug("arr[%d]: %d\n", id, cnt);
        arr[id] = cnt;
    }  
    
    return arr;
}
