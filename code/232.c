#define MaxStackSize 105

typedef struct {
    int* data;
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* s = malloc(sizeof(MyStack));
    s->data = malloc(sizeof(int)*MaxStackSize);
    s->top = -1;
    return s;
}

void myStackPush(MyStack* s, int x) {
    s->data[++(s->top)] = x;
}

int myStackPop(MyStack* s) {
    return s->data[s->top--];
}

int myStackTop(MyStack* s) {
    return s->data[s->top];
}

bool myStackEmpty(MyStack* s) {
    return s->top == -1;
}

void myStackFree(MyStack* s) {
    free(s->data);
    free(s);
}

typedef struct {
    MyStack *in, *out;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = malloc(sizeof(MyQueue));
    q->in = myStackCreate();
    q->out = myStackCreate();
    return q;
}

void myQueuePush(MyQueue* q, int x) {
    myStackPush(q->in, x);
}

int myQueuePop(MyQueue* q) {
    if(myStackEmpty(q->out)){
        while(!myStackEmpty(q->in)){
            myStackPush(q->out, myStackPop(q->in));
        }
    }
    return myStackPop(q->out);
}

int myQueuePeek(MyQueue* q) {
    if(myStackEmpty(q->out)){
        while(!myStackEmpty(q->in)){
            myStackPush(q->out, myStackPop(q->in));
        }
    }
    return myStackTop(q->out);
}

bool myQueueEmpty(MyQueue* q) {
    return myStackEmpty(q->in) & myStackEmpty(q->out);
}

void myQueueFree(MyQueue* q) {
    myStackFree(q->in);
    myStackFree(q->out);
    free(q);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/