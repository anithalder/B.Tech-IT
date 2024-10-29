#include <stdio.h>
#define max 10

void rotate(int arr[], int n, int pos);

int main()
{
    int num, arr[max], pos;
    printf("Enter how many elements you want: ");
    scanf("%d", &num);

    printf("Enter the array elements: ");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("The position of rotation: ");
    scanf("%d", &pos);

    printf("The array is:");
    for (int i = 0; i < num; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    rotate(arr, num, pos);

    printf("The rotated array is:");
    for (int i = 0; i < num; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}

void rotate(int arr[], int n, int pos)
{
    // Adjust position to be within bounds
    if (pos > n)
    {
        pos = pos % n;
    }

    // Create a temporary array to hold the rotated values
    int temp[max];

    for (int i = 0; i < n; i++)
    {
        temp[(i + pos) % n] = arr[i];
    }

    // Step 3: Copy back from temp to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
