#include <iostream>
#include <climits>
using namespace std;

int binarySearch(int *, int *, int *, int *);

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3}, target = 5;
    int start = 0, end = (sizeof(arr) / sizeof(arr[0]) - 1);
    int result = binarySearch(arr, &start, &end, &target);
    if (result == -1)
    {
        cout << "\nElement not present in the array!\n\n";
        exit(0);
    }
    cout << "\nThe element found at " << result + 1 << "th position\n\n";
}

int binarySearch(int *arr, int *start, int *end, int *target)
{
    int mid = *start + (*end - *start) / 2;

    if (*start > *end)
        return -1;
    if (arr[mid] == *target)
        return mid;

    // if (arr[mid] < *target)
    // {
    //     *start = mid + 1;
    //     return binarySearch(arr, start, end, target);
    // }
    // else
    // {
    //     *end = mid - 1;
    //     return binarySearch(arr, start, end, target);
    // }

    if (arr[*start] <= arr[mid]) // Left sorted or not
    {
        if (arr[*start] <= *target <= arr[mid]) // Checks the target will exists in left or not
        {
            if (*target < arr[mid])
            {
                *end = mid - 1;
                return binarySearch(arr, start, end, target);
            }
            else
            {
                *start = mid + 1;
                return binarySearch(arr, start, end, target);
            }
        }
    }
    else // Right sorted
    {
        if (arr[mid] <= *target <= arr[*end]) // Checks the target will exists in right or not
        {
            if (*target < arr[mid])
            {
                *end = mid - 1;
                return binarySearch(arr, start, end, target);
            }
            else
            {
                *start = mid + 1;
                return binarySearch(arr, start, end, target);
            }
        }
    }
}