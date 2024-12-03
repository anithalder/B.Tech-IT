#include <iostream>
using namespace std;

void swap(int *, int *);
void bubble_sort(int *, int);

int main()
{
    int arr[] = {2, 1, 5, 8, 3, 6}, size = sizeof(arr) / sizeof(arr[0]) - 1;

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
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}