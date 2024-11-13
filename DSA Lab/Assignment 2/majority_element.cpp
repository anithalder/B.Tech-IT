#include <stdio.h>
#define MAX 10

void main(int argc, char const *argv[])
{
	int arr[MAX], num;
	printf("How many element you want: ");
	scanf("%d",&num);
	printf("Enter the array elements: ");
	for (int i = 0; i < num; ++i)	// For inserting array elemens
	{
		scanf("%d",&arr[i]);
	}
	/*
	for (int i = 0; i < num; ++i)
	{
		
	}
	*/
	for (int i = 0; i < num; ++i)	// Calculating the frequency of each element
	{
		int frequency = 0;
		for (int j = 0; j < num; ++j)
		{
			if (arr[i] == arr[j])
			{
				frequency ++;
			}
		}
		if(frequency > num/2)
		{
			printf("Mejority element is: %d\n", arr[i]);
			break;
		}
	}
}
