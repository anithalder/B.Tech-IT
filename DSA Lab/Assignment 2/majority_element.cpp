#include <stdio.h>
#define MAX 10

int main(int argc, char const *argv[])
{
    int arr[MAX], num;
    printf("How many elements you want: ");
    scanf("%d", &num);
    printf("Enter the array elements: ");
    for (int i = 0; i < num; ++i) // For inserting array elements
        scanf("%d", &arr[i]);
    
    int foundMajority = 0; // Flag to track if a majority element is found
    for (int i = 0; i < num; ++i) // Calculating the frequency of each element
    {
        int frequency = 0;
        for (int j = 0; j < num; ++j)
        {
            if (arr[i] == arr[j])
            {
                frequency++;
            }
        }
        if (frequency >= num / 2)
        {
            printf("Majority element is: %d", arr[i]);
            foundMajority = 1; // Set the flag to indicate a majority element is found
            break;
        }
    }

    if (!foundMajority) // Check if no majority element was found
        printf("No majority element exists");
    
	return 0;
}
