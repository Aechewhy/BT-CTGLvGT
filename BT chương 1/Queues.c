#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int capacity;
    int head;
    int tail;
    int *items;
} Queue;
Queue* createQueue(int capacity)
{
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if(q==NULL) return NULL;
    q->capacity=capacity;
    q->items = (int*) malloc(sizeof(int)*q->capacity);
    if(q->items==NULL)
    {
        free(pq);
        return NULL;
    }
    q->head=q->tail=-1;
    return q;
}
void destroyQueue(Queue* q)
{   
    if(q==NULL) return NULL;
    free(q->items);
    free(q);
}
int isFull(Queue* q)
{
    return ((pq->tail + 1) % pq->capacity == pq->head);
}
int isEmpty(Queue* q)
{
    return (q->head== -1 && q->tail==-1);
}
void enqueue(Queue* q, int value)
{
    if(isFull(q)) return;
    if(isEmpty(q)) 
        q->head=q->tail=0;
    else q->tail= (q->tail+1)% q->capacity;
    q->items[q->tail]=value;
}
int dequeue(Queue* q)
{
    if(isEmpty(q)) return -1;
    int value=q->items[q->head];
    if(q->head==q->tail)
        q->head=q->tail=-1;    
    else q->head= (q->head+1)%q->capacity;
    return value;
}
int peek(Queue* q)
{
    if (isEmpty(q)) return -1; 
    return q->items[q->head];
}

int main()
{
    return 0;
}