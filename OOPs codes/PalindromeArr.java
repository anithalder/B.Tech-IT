import java.util.Scanner;

class PalindromeArr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter how many element you want: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the space separated array elements: ");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        boolean isPalindrome = true;

        for (int i = 0; i < n / 2; i++) {
            if (arr[i] != arr[n - i - 1]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome)
            System.out.println("Array is palindrome");
        else
            System.out.println("Array is not palindrome");

        sc.close();
    }
}
