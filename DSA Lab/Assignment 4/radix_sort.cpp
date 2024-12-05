#include <iostream>
#include <climits>
#define N 10
using namespace std;

int get_digit(int, int);
int find_max(int *, int);
void radix_sort(int *, int);
void count_sort(int *, int, int);

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "The unsorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    radix_sort(arr, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;

    return 0;
}

void radix_sort(int *arr, int size)
{
    for (int place = 1; find_max(arr, size) / place > 0; place *= 10)
        count_sort(arr, size, place);
}

void count_sort(int *arr, int size, int place)
{
    int output[size], count[N] = {0};

    for (int i = 0; i < size; i++)
    {
        int digit = get_digit(arr[i], place);
        count[digit]++;
    }

    for (int i = 1; i < N; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = get_digit(arr[i], place);
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

int get_digit(int num, int place)
{
    return (num / place) % 10;
}

int find_max(int *arr, int size)
{
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}