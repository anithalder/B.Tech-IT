#include <iostream>
using namespace std;

void swap(int *, int *);
void heapSort(int *arr, int);
void build_max_heap(int *, int size);
void heapify(int *, int, int);

int main()
{
    int arr[] = {2, 1, 5, 8, 3, 6}, size = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "The unsorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    heapSort(arr, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    return 0;
}

void heapSort(int *arr, int size)
{
    build_max_heap(arr, size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, size, 0);
    }
}

void build_max_heap(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}