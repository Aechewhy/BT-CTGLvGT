#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int top;
    int capacity;
    int *items;
} Stack;
Stack* createStack(int capacity){
    Stack* stk= (Stack*) malloc(sizeof(Stack));
    if(stk==NULL) return NULL;
    stk->capacity=capacity;
    stk->items = (int*) malloc(sizeof(int)* stk->capacity);
    if(stk->items==NULL) return NULL;
    return stk;
}
void destroyStack(Stack* stk)
{   
    if(stk==NULL) return;
    free(stk->items);
    free(stk);
}
int isEmpty(Stack *stk)
{
    return stk->top == -1;
}
int isFull(Stack *stk)
{
    return stk->top == stk->capacity+1;
}
void push(Stack* stk, int value)
{
    stk->items[++(stk->top)] = value;
}
int pop(Stack* stk)
{
    if(isEmpty(stk)) return -1; 
    return stk->items[(stk->top)--];
}
void setValue(Stack *stk, int n)
{
    for(int i=0; i<n; i++)
    {   
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d",&stk->items[i]);
    }
    stk->top=n-1;
}
void printAllValue(Stack *stk)
{
    for(int i=0; i < stk->capacity; i++)
    {
        printf("Phan tu thu %d: %d\n", i+1, stk->items[i]);
    }
    printf("\n");
}
void reverseStack(Stack *stk)
{   
    int count=stk->top+1;
    int *arr=(int*) malloc(sizeof(int)*count);
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<count; i++)
    {
        arr[i]=pop(stk);
    }
    for(int i=0; i<count; i++)
    {
        push(stk,arr[i]);
    }
    free(arr);
}
int main(){
    int capacity;
    Stack *stk;
    printf("Nhap so phan tu cua day: ");
    scanf("%d", &capacity);
    stk = createStack(capacity);
    setValue(stk, capacity);
    printAllValue(stk);
    
    reverseStack(stk);
    printAllValue(stk);
    destroyStack(stk);
    
}