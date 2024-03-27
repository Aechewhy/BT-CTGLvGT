#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int value;
    int priority;
} item;
typedef struct {
    int capacity;
    int head;
    int tail;
    item *Items;
} Priority_Queue; 
//Create a new PQ
Priority_Queue* createPQ(int capacity)
{
    Priority_Queue* pq = (Priority_Queue*) malloc(sizeof(Priority_Queue));
    if(pq==NULL) return NULL;
    pq->capacity=capacity;
    pq->Items=(item*) malloc(sizeof(item)*capacity);
    if(pq->Items==NULL) 
    {
        free(pq);
        return NULL;
    }
    pq->head=pq->tail=-1;
    return pq;
}
//Destroy a PQ
void destroyPQ(Priority_Queue* pq)
{
    free(pq->Items);
    free(pq);
}
//Check if the PQ is full
int isFull(Priority_Queue* pq)
{
    return ((pq->tail + 1) % pq->capacity == pq->head);
}
//Check if the PQ is empty
int isEmpty(Priority_Queue* pq)
{
    return (pq->head== -1 && pq->tail==-1);
}
//Enqueue an item
void enqueue_item(Priority_Queue* pq, item a)
{
    if(isFull(pq)) exit(-1);
    if(isEmpty(pq))
    {
        pq->head=pq->tail=0;
    }
    else pq->tail=(pq->tail+1)%pq->capacity;
    pq->Items[pq->tail] = a;
}
//Enqueue by value and priority
void enqueue_value_priority(Priority_Queue* pq , int value, int priority)
{   
    item newItem;
    newItem.value = value;
    newItem.priority = priority;
    enqueue_item(pq, newItem);
}
//Find the index has the highest priority
int highest_priority(Priority_Queue* pq) 
{
    int max = pq->head;
    int current=(pq->head+1)%pq->capacity;
    while(current!= (pq->tail+1) % pq->capacity) 
    {
        if (pq->Items[current].priority > pq->Items[max].priority)
            max = current;
        else if (pq->Items[current].priority == pq->Items[max].priority && current < max)
            max = current;
        current=(current+1)%pq->capacity;
    }
    return max;
}
//Dequeue and return an item
item dequeue_item(Priority_Queue* pq) 
{
    if (isEmpty(pq))
        exit(-1); 
    item dequeuedItem = pq->Items[highest_priority(pq)];
    if (pq->head == pq->tail)
        pq->head = pq->tail = -1;
    else
        pq->head = (pq->head + 1) % pq->capacity;
    return dequeuedItem;
}
//Get the item without dequeueing
item peek(Priority_Queue* pq) 
{
    if(isEmpty(pq)) exit(-1);
    return pq->Items[highest_priority(pq)];
}
//Print all items
void printAllItems(Priority_Queue* pq)
{
    if(isEmpty(pq))
    {
        printf("Priority queue is empty.\n");
        return;
    }
    int current = pq->head;
    int count=1;
    while(current != (pq->tail + 1) % pq->capacity)
    {
        printf("Items %d:        ", count);
        printf("Value: %d         ", pq->Items[current].value);
        printf("Priority: %d\n",pq->Items[current].priority);
        current = (current+1)%pq->capacity;
        count++;
    }
}
int main()
{   
    Priority_Queue* a = createPQ(5);
    enqueue_value_priority(a, 5,1);
    enqueue_value_priority(a, 3,2);
    enqueue_value_priority(a, 2,2);
    enqueue_value_priority(a, 4,1);
    dequeue_item(a);
    printAllItems(a);
    
    destroyPQ(a);
    return 0;
}