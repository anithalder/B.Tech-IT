#include <stdio.h>
#define MAX 10

void remove_duplicate(int *arr, int *num);

int main()
{
    int arr[MAX], num;
    printf("Enter how many elements you want (max %d): ", MAX);
    scanf("%d", &num);

    if (num <= 0 || num > MAX)
    {
        printf("\n\tInvalid input!\n\n");
        return 1; // Exit on invalid input
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    remove_duplicate(arr, &num);

    printf("The array after remove duplicate is: ");
    for (int i = 0; i < num; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}

void remove_duplicate(int *arr, int *num)
{
    int temp[MAX], k = 0; // Start k at 0
    for (int i = 0; i < *num; i++)
    {
        int flag = 0;               // Reset flag for each element
        for (int j = 0; j < k; j++) // Check against current unique elements
        {
            if (arr[i] == temp[j])
            {
                flag = 1;
                break; // Break early if a duplicate is found
            }
        }
        if (!flag)
        {
            temp[k++] = arr[i]; // Only add if not a duplicate
        }
    }
    *num = k; // Update the count of unique elements
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i]; // Copy unique elements back to original array
    }
}
