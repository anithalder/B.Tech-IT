#include <stdio.h>
#include <stdlib.h>
#define max 10

void reverse(int arr[], int n);

void main()
{
    int arr[max], num, pos;
    printf("Enter how many elements you want: ");
    scanf("%d", &num);

    printf("Enter the array elements: ");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("The array is:");
    for (int i = 0; i < num; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    reverse(arr, num);

    printf("The reverse array is:");
    for (int i = 0; i < num; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// github token : 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

void reverse(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}