#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, len = INT_MIN, givenSum = 6;
    int start = -1, end = -1; // Initialize start and end

    cout << "The array is: ";
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        cout << arr[i] << " ";
    cout << "\nThe given sum is: " << givenSum;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        int sum = 0;
        for (int j = i; j < (sizeof(arr) / sizeof(arr[0])); j++)
        {
            // for (int k = i; k <= j; k++) // Change to <= to include arr[j]
            sum += arr[j];
            if (sum <= givenSum)
            {
                if (j - i + 1 > len) // Update length and start/end indices
                {
                    len = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }

    if (start == -1 && end == -1)
        cout << "No subarray found with the given sum." << endl;
    else
    {
        cout << "\nThe longest subarray of sum " << givenSum << " is: [";
        for (int i = start; i <= end; i++)
        {
            cout << arr[i];
            if (i < end)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
