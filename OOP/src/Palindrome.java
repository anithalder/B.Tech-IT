import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int size = sc.nextInt();
        int[] arr = new int[size];
        int[] rev = new int[size];

        System.out.print("Enter the array elements: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        // Reverse the array and store in rev
        for (int i = 0; i < size; i++) {
            rev[i] = arr[size - 1 - i]; // Directly reverse while storing
        }

        boolean isPalindrome = true; // Flag to check palindrome status

        // Compare the original array with the reversed array
        for (int i = 0; i < size; i++) {
            if (arr[i] != rev[i]) {
                isPalindrome = false;
                break; // No need to check further if a mismatch is found
            }
        }

        System.out.print("The reversed array is: ");
        for (int i = 0; i < size; i++) {
            System.out.print(rev[i] + " ");
        }

        if (isPalindrome) {
            System.out.println("\nThe array is a palindrome.");
        } else {
            System.out.println("\nThe array is not a palindrome.");
        }
    }
}
