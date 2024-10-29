#include <stdio.h>
#include <stdlib.h>
#define max 10
int *intersection(int arr1[], int arr2[], int n1, int n2, int *size);

void main()
{
    int arr1[max], arr2[max], n1, n2, size = 0;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements in the first array: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements in the second array: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int *temp = intersection(arr1, arr2, n1, n2, &size);

    printf("The intersection of the two arrays is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

int *intersection(int arr1[], int arr2[], int n1, int n2, int *size)
{
    int *temp = (int *)malloc(max * sizeof(int)), k = 0;
    if (n1 > n2)
    {
        intersection(arr2, arr1, n2, n1, size);
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                int found = 0;
                for (int l = 0; l < k; l++)
                {
                    if (temp[l] == arr1[i])
                    {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    temp[k++] = arr1[i];
                }
                break;
            }
        }
    }
    *size = k;
    return temp;
}