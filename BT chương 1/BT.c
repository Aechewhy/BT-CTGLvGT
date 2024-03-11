#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert(int arr[], int *size, int index, int value)
{   
    if(index < 0||index > *size) return;
    if(*size>=MAX) return;
    for(int i=*size; i>index; i--)
        arr[i]=arr[i-1];
    arr[index]=value;
    (*size)++;
}
void delete(int arr[], int* size, int index)
{
    if(*size==0) return;
    if(index > *size||index<0) return;
    for(int i=index; i<*size; i++)
        arr[i]=arr[i+1];
    (*size)--;
}
//Ghep hai mang da sap xep thanh mot mang da sap xep
int* merge(int arr1[], int size1, int arr2[], int size2) 
{
    int *mergedArr = (int*)malloc((size1 + size2) * sizeof(int));
    if (mergedArr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int i = 0, j = 0, count = 0;
    while (i < size1 && j < size2) 
    {
        if (arr1[i] <= arr2[j]) 
            mergedArr[count++] = arr1[i++];
        else 
            mergedArr[count++] = arr2[j++];
    }

    while (i < size1) 
        mergedArr[count++] = arr1[i++];

    while (j < size2)
        mergedArr[count++] = arr2[j++];
}
void print(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main(){
    int a[6]={1,2,3,4,5,6};
    int b[3]={3,5,7};
    int *p = merge(a,6,b,3);
    print(p,9);
    free(p);
    return 0;
}