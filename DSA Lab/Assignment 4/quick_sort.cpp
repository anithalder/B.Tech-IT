#include <iostream>
using namespace std;

void swap(int *, int *);
void quick_sort(int *, int, int);
int partition(int *arr, int start, int end);

int main()
{
    int arr[] = {2, 1, 5, 8, 3, 6}, size = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "The unsorted array is: ";
    for (int i = 0; i <= size; i++)
        cout << " " << arr[i];

    cout << endl;

    quick_sort(arr, 0, size);

    cout << "The sorted array is: ";
    for (int i = 0; i <= size; i++)
        cout << " " << arr[i];

    cout << endl;

    return 0;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[start], i = start, j = end;

    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (j > i)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[start], &arr[j]);
    
    return j;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
