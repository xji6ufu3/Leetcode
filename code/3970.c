#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

static int debug_on;

#define debug(...) do{if(debug_on) fprintf(stderr, "[debug] " __VA_ARGS__); }while(0)

typedef struct linkl{
    int node;
    long long weight;
    struct linkl *next;
} linkl;

typedef struct{
    int weight;
    int node;
    int consecutiveC;
} heapNode;

static inline void swapNode(heapNode *a, heapNode *b){
    heapNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapPush(heapNode *heap, int *heapSize, heapNode *node, int maxHeapSize){
    if(*heapSize == maxHeapSize){
        debug("[heapPush] reach the maxHeapSize.\n");
        return;
    }
    
    int newnode = (*heapSize)++;
    heap[newnode] = *node;

    while(newnode > 0){
        int father = (newnode - 1) / 2;
        if(heap[newnode].weight < heap[father].weight){
            swapNode(&heap[newnode], &heap[father]);
            newnode = father;
        } else{
            break;
        }
    }
}

void heapPop(heapNode *heap, int *heapSize){
    if(*heapSize < 1){
        debug("[heapPop] pop when heap is empty.\n");
        return;
    }

    heap[0] = heap[*heapSize - 1];
    --(*heapSize);

    int ptr = 0;
    while(true){
        int left = 2 * ptr + 1, right = 2 * ptr + 2;

        long long lw = left < *heapSize ? heap[left].weight : LLONG_MAX;
        long long rw = right < *heapSize ? heap[right].weight : LLONG_MAX;
        long long pw = heap[ptr].weight;

        if(lw != LLONG_MAX && lw < rw && pw > lw){
            swapNode(&heap[left], &heap[ptr]);
            ptr = left;
        } else if(rw != LLONG_MAX && rw <= lw && pw > rw){
            swapNode(&heap[right], &heap[ptr]);
            ptr = right;
        } else{
            break;
        }
    }
}

static inline const heapNode* heapTop(heapNode *heap){
    return &heap[0];
}

long long dijkstra(int n, int edgesSize, char *labels, int k, linkl **adjacent){
    int stride = k + 1;
    int totalStates = n * stride;
    
    bool *vis = (bool*)calloc(totalStates, sizeof(bool));
    long long *dis = (long long*)malloc(sizeof(long long) * totalStates);

    for(int i = 0; i < totalStates; ++i){
        vis[i] = false;
        dis[i] = LLONG_MAX;
    }
    dis[0 * stride + 1] = 0;

    int maxHeapSize = edgesSize * k + n + 5;
    heapNode *minheap = (heapNode*)malloc(sizeof(heapNode) * maxHeapSize); // priority queue -> min heap
    int heapSize = 0;

    heapPush(minheap, &heapSize, &(heapNode){.weight = dis[0], .node = 0, .consecutiveC = 1}, maxHeapSize);

    while(heapSize){
        int node = heapTop(minheap)->node;
        int consecutiveC = heapTop(minheap)->consecutiveC;
        int state = node * stride + consecutiveC;

        heapPop(minheap, &heapSize);

        if(vis[state]) continue;
        vis[state] = true;

        linkl *ptr = adjacent[node];
        
        while(ptr){
            int dest = ptr->node, weight = ptr->weight;

            int nextC = (labels[dest] == labels[node]) ? consecutiveC+1 : 1;
            
            if(nextC <= k){
                int nextState = dest * stride + nextC;

                if(dis[state] + weight < dis[nextState]){ // relax
                    dis[nextState] = dis[state] + weight;
                    heapPush(minheap, &heapSize, &(heapNode){.weight = dis[nextState], .node = dest, .consecutiveC = nextC}, maxHeapSize);
                }
            }

            ptr = ptr->next;
        }
    }

    long long ans = LLONG_MAX;
    for(int c = 1; c <= k; ++c){
        if(dis[(n - 1) * stride + c] < ans){
            ans = dis[(n - 1) * stride + c];
        }
    }

    free(vis);
    free(dis);
    free(minheap);

    return ans;
}

int shortestPath(int n, int** edges, int edgesSize, int* edgesColSize, char* labels, int k) {
    // notice: directed edge, cycle
    // use dijkstra

    linkl *adjacent[n], *adjEnd[n];

    for(int i = 0; i < n; ++i){
        adjEnd[i] = adjacent[i] = NULL;
    }

    for(int i = 0; i < edgesSize; ++i){
        int start = edges[i][0], dest = edges[i][1], weight = edges[i][2];

        if(adjacent[start] == NULL){
            adjacent[start] = (linkl*)malloc(sizeof(linkl));
            adjEnd[start] = adjacent[start];
        } else{
            adjEnd[start]->next = (linkl*)malloc(sizeof(linkl));
            adjEnd[start] = adjEnd[start]->next;
        }

        adjEnd[start]->node = dest;
        adjEnd[start]->weight = weight;
        adjEnd[start]->next = NULL;
    }

    int ret = dijkstra(n, edgesSize, labels, k, adjacent);

    for(int i = 0; i < n; ++i){
        linkl *ptr = adjacent[i];
        while(ptr){
            linkl *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }

    return ret == LLONG_MAX ? -1 : ret;
}

int main(){
    debug_on = getenv("DEBUG") != NULL;

    int n, k, edgesSize;
    char labels[3+1];

    printf("n: ");
    scanf("%d", &n);
    printf("edgesSize: ");
    scanf("%d", &edgesSize);

    int edges[edgesSize][3];

    printf("edges %dx3: \n", edgesSize);
    for(int i = 0; i < edgesSize; ++i){
        for(int j = 0; j < 3; ++j){
            scanf("%d", &edges[i][j]);
        }
    }
    printf("labels: ");
    scanf("%s", labels);
    printf("k: ");
    scanf("%d", &k);

    int *edgesPointer[edgesSize];
    for(int i = 0; i < edgesSize; ++i){
        edgesPointer[i] = edges[i];
    }

    printf("Ans: %d\n", shortestPath(n, edgesPointer, edgesSize, NULL, labels, k));

    return 0;
}
