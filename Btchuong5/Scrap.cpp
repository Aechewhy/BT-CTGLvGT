#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//! Heap sort
void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[i])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}
void heapSort(vector<int> &arr)
{
    // This loop is used for building max heap the first time;
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);
    // This loop is used for sorting the list and rebuilding max heap after sorting
    int size = arr.size();
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);  // swap the root and the leaf
        size--;                // reduce the size
        heapify(arr, size, 0); // re-heapify
    }
}
//! Merge sort
void mergeSort(vector<int> arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    if (mid > left)
        mergeSort(arr, mid, right);
    if (mid + 1 < right)
        mergeSort(arr, left, mid);
}
void merge(vector<int> &arr, int left, int mid, int right)
{
    int size1 = mid - left - 1;
    int size2 = right - mid;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i <= mid - left - 1; i++)
    {
        arr1.push_back(arr[i]);
    }
    for (int i = 0; i <= right - mid; i++)
        arr2.push_back(arr[i]);
    for (int i = 0, j = 0; i < mid - left + 1, j < right - mid;)
    {
        if ((i == size1) || (j < size2 && arr1[i] > arr2[j]))
        {
            arr.push_back(arr2[j]);
            j++;
        }
        else
        {
            arr.push_back(arr1[i]);
            i++;
        }
    }
}
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    cout << "Sorted array is \n";
    for (int i : arr)
        cout << i << " ";

    return 0;
}