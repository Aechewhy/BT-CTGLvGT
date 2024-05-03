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
int KhusumArray(vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
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
// Bai 3 //! sai cmnr
int findSmallestNumber(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return min(nums[0], nums[1]);
    nums.erase(nums.begin());
    return min(nums[0], findSmallestNumber(nums));
}
int KhufindSmallestNumber(vector<int> nums)
{
    int minVal = nums[0];
    for (int n : nums)
        minVal = min(minVal, n);
    return minVal;
}
// Bai 4
template <typename T>
int Power(T x, int y)
{
    if (y == 0)
        return 1;
    if (y > 0)
        return x * Power(x, y - 1);
    return 1.0 / (x * Power(x, -y));
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
    vector<int> Arr = {9, 2, 3, 4, 1, 8, 9};
    // cout << sumArray(Arr, 0) << endl;
    // cout << KhusumArray(Arr, 0) << endl;
    // cout << sumOfDigits(123) << endl;
    // cout << KhusumOfDigits(123) << endl;
    cout << findSmallestNumber(Arr) << endl;
    // cout << Power(2, -4);
    return 0;
}