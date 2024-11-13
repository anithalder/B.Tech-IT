#include <iostream>
#include <climits>
using namespace std;

int binarySearch(int *, int *, int *, int *);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}, target = 5;
    int start = 0, end = (sizeof(arr) / sizeof(arr[0]) - 1);
    int result = binarySearch(arr, &start, &end, &target);
    if (result == -1)
    {
        cout << "\nElement not present in the array!\n\n";
        exit(0);
    }
    cout << "\nThe element found at " << result << "th position\n\n";
}

int binarySearch(int *arr, int *start, int *end, int *target)
{
    int mid = *start + (*end - *start) / 2;
    if (*start > *end)
    {
        return -1;
    }
    if (arr[mid] == *target)
    {
        return mid;
    }
    if (arr[mid] < *target)
    {
        *start = mid + 1;
        return binarySearch(arr, start, end, target);
    }
    if (arr[mid] > *target)
    {
        *end = mid - 1;
        return binarySearch(arr, start, end, target);
    }
}