#include <iostream>
#include <climits>
using namespace std;

int largestSumSubarray(int *, int *);

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The largest sum subarray is " << largestSumSubarray(arr, &size);
}

int largestSumSubarray(int *arr, int *size)
{
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < *size; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}