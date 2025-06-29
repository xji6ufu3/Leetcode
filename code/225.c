#define MaxQueueSize 105

typedef struct{
    int* data;
    int front, rear;
} MyQueue;

MyQueue* createQueue(){
    MyQueue* q;
    q = malloc(sizeof(MyQueue));
    q->front = q->rear = 0;
    q->data = malloc(sizeof(int)*MaxQueueSize);
    return q;
}

int myQueueLen(MyQueue* q){
    return (q->rear - q->front + MaxQueueSize) % MaxQueueSize;
}

int myEnQueue(MyQueue* q, int x) {
    if(myQueueLen(q) + 1 == MaxQueueSize) return -1;
    q->data[q->rear++] = x;
    q->rear %= MaxQueueSize;
    return 0;
}

int myDeQueue(MyQueue* q){
    if(myQueueLen(q) == 0) return -1;
    int val = q->data[q->front++];
    q->front %= MaxQueueSize;
    return val;
}

void myQueueFree(MyQueue* q){
    free(q->data);
    free(q);
}

typedef struct {
    MyQueue* q;
} MyStack;


MyStack* myStackCreate() {
    MyStack* s = malloc(sizeof(MyStack));
    s->q = createQueue();
    return s;
}

void myStackPush(MyStack* obj, int x) {
    myEnQueue(obj->q, x);
}

int myStackPop(MyStack* obj) {
    int len = myQueueLen(obj->q);
    if(len == 0) return -1;
    for(int i = len; i > 1; i--){
        myEnQueue(obj->q, myDeQueue(obj->q));
    }
    return myDeQueue(obj->q);
}

int myStackTop(MyStack* obj) {
    int val = myStackPop(obj);
    myStackPush(obj, val);
    return val;
}

bool myStackEmpty(MyStack* obj) {
    return myQueueLen(obj->q) == 0;
}

void myStackFree(MyStack* obj) {
    myQueueFree(obj->q);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/