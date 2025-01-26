#include <iostream>
using namespace std;

void swap(int *, int *);
void heapSort(int *arr, int);
void build_max_heap(int *, int size);
void heapify(int *, int, int);

int main()
{
    int size;
    cout << "How many element you want to insert: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "Invalid input";
        exit(0);
    }

    int arr[size]; // Dynamically allocate based on the size input
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

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
    build_max_heap(arr, size); // Build the initial max heap

    // Perform heap sort
    for (int i = size - 1; i > 0; i--) // Start from the end of the array
    {
        swap(&arr[0], &arr[i]); // Move the largest element to the end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

void build_max_heap(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) // Start heapifying from the last non-leaf node
        heapify(arr, size, i);
}

void heapify(int *arr, int size, int i)
{
    int largest = i;       // Assume the current node is the largest
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if the left child exists and is greater than the current largest
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // Check if the right child exists and is greater than the current largest
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the current node
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]); // Swap the current node with the largest
        heapify(arr, size, largest);  // Recursively heapify the affected subtree
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
