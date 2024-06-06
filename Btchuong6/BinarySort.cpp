#include <iostream>
#include <vector>
using namespace std;

int BSearch(vector<int> &arr, int key, int first, int last)
{
    if (first > last)
        return -1;
    int mid = first + (last - first) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return BSearch(arr, key, first, mid - 1);
    return BSearch(arr, key, mid + 1, last);
};
int binarySearch(vector<int> &arr, int key)
{
    return BSearch(arr, key, 0, arr.size() - 1);
}
int main()
{
    vector<int> vals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 9;
    int result = binarySearch(vals, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
