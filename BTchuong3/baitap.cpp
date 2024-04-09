#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sumArray(vector<int> nums, int index)
{
    if (nums.size() == index)
        return 0;
    else
    {
        return nums[index] + sumArray(nums, index + 1);
    }
}
//! Ham khu de quy
int KhusumArray(vector<int> nums, int index)
{
    int sum = 0;
    while (index != nums.size())
    {
        sum += nums[index];
        index++;
    }
    return sum;
}
int sumOfDigits(int num)
{
    if (num < 10)
        return num % 10;
    return num % 10 + sumOfDigits(num % 10);
}
int KhusumOfDigits(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int findSmallestNumber(vector<int> nums)
{
    if (nums.size() == 2)
        return min(nums[0], nums[1]);
    nums.pop_back();
    return min(nums[0], findSmallestNumber(nums));
}
int KhufindSmallestNumber(vector<int> nums)
{
    int minVal = nums[0];
    for (int n : nums)
        minVal = min(minVal, n);
    return minVal;
}
int Power(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    return x * Power(x, y - 1);
}
int KhuPower(int x, int y)
{
    if (y == 0)
        return 1;
    int result = x;
    for (int i = 0; i < y - 1; i++)
        result *= x;
    return result;
}
// another way
int power(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

int main()
{
    vector<int> Arr = {1, 2, 3, 4, 5};
    // cout << sumArray(Arr, 0) << endl;
    // cout << KhusumArray(Arr, 0) << endl;
    // cout << sumOfDigits(123) << endl;
    // cout << KhusumOfDigits(123) << endl;
    // cout << KhufindSmallestNumber(Arr) << endl;
    cout << power(2, 6);
    return 0;
}