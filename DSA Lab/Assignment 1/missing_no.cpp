#include <stdio.h>
#include <stdlib.h>
#define max 10

int main(int argc, char const *argv[])
{
  int arr[max], num, sum = 0, expected_sum = 0;

  printf("Enter how many elements you want (up to %d): ", max);
  scanf("%d", &num);

  if (num > max)
  {
    printf("Number exceeds maximum limit of %d.\n", max);
    return 1; // Exit if the number exceeds the limit
  }

  printf("Enter the elements (from 1 to %d): ", num);
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  for (int i = 0; i < num - 1; i++)
    sum += arr[i]; // Sum of entered numbers

  // Calculate the expected sum of the first 'num' natural numbers
  expected_sum = num * (num + 1) / 2;

  // Find the missing number
  printf("The missing number is: %d\n", expected_sum - sum);

  return 0;
}
