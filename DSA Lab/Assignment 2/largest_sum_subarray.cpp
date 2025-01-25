#include <iostream>
#include <climits>
using namespace std;

int largestSumSubarray(int *, int *);

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The array is: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << " with sum " << largestSumSubarray(arr, &size);
}

int largestSumSubarray(int *arr, int *size)
{
    int maxSum = INT_MIN, currSum = 0;
    int start = 0, end = 0, tempStart = 0;
    for (int i = 0; i < *size; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        start = tempStart, end = i;
        if (currSum < 0)
        {
            currSum = 0;
            tempStart = i + 1;
        }
    }
    cout << "The largest subarray is: [ ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << "]";
    return maxSum;
}