#include <iostream>
#include <climits>
using namespace std;
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main()
{
    int arr[] = {2, 4, 1, 6, 7, 9};
    int start = 0, end = (sizeof(arr) / sizeof(arr[0]) - 1);

    cout << "Before sorting the array: ";
    for (int i = start; i <= end; i++)
        cout << " " << arr[i];

    cout << endl;

    mergeSort(arr, start, end);

    cout << "The sorted array is: ";
    for (int i = start; i <= end; i++)
        cout << " " << arr[i];

    cout << endl;
    return 0;
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end)
{
    int temp[end];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}