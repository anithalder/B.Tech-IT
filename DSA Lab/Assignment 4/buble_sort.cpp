#include <iostream>
using namespace std;

void swap(int *, int *);
void bubble_sort(int *, int);

int main()
{
    int arr[10], size = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << "How many element you want to insert: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "Invalid input";
        exit(0);
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "The unsorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    bubble_sort(arr, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    return 0;
}

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}