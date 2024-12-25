#include <iostream>
using namespace std;

void swap(int *, int *);
void quick_sort(int *, int, int);
int partition(int *, int, int);

void print_array_with_pointer(int *arr, int size, int ptr1 = -1, int ptr2 = -1, int pivotIndex = -1)
{
    for (int i = 0; i <= size; i++)
    {
        if (i == pivotIndex)
            cout << "(" << arr[i] << ")"; // Show pivot element in parentheses
        else
            cout << " " << arr[i];

        if (i == ptr1 || i == ptr2)
            cout << "^"; // Pointer to indicate change
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 2, 8, 4, 3, 7, 6}, size = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "Initial array: ";
    print_array_with_pointer(arr, size);

    quick_sort(arr, 0, size);

    cout << "Sorted array: ";
    print_array_with_pointer(arr, size);

    return 0;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        cout << "\nAfter partitioning with pivot at index " << pivot << ": ";
        print_array_with_pointer(arr, end, -1, -1, pivot);

        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[start], i = start, j = end;

    while (i < j)
    {
        while (i <= end && arr[i] <= pivot)
            i++;

        while (j >= start && arr[j] > pivot)
            j--;

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
            cout << "\nSwapped elements at indices " << i << " and " << j << " (pivot: " << pivot << "): ";
            print_array_with_pointer(arr, end, i, j, start);
        }
    }

    swap(&arr[start], &arr[j]);
    cout << "\nSwapped pivot element with element at index " << j << " (pivot: " << pivot << "): ";
    print_array_with_pointer(arr, end, start, j, j);

    return j;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

