#include <stdio.h>
#include <stdlib.h>
#define max 10

void reverse(int arr[], int n);

int main()
{
    int arr[max], num;
    printf("Enter how many elements you want: ");
    scanf("%d", &num);
    if (num < 1)
    {
        printf("Invalid input\n");
        exit(0);
    }
    printf("Enter the array elements: ");
    for (int i = 0; i < num; ++i)
        scanf("%d", &arr[i]);

    printf("The array is:");
    for (int i = 0; i < num; ++i)
        printf(" %d", arr[i]);
    printf("\n");

    reverse(arr, num);

    printf("The reverse array is:");
    for (int i = 0; i < num; ++i)
        printf(" %d", arr[i]);
    printf("\n");
    return 0;
}

void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}