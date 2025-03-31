import java.util.Scanner;

public class SwitchCase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // System.out.print("Enter the size of array: ");
        // int size = sc.nextInt();
        int[] arr = new int[] { 10, 20, 30, 40 };

        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();

        switch (choice) {
            case 0:
                System.out.print("The value is: " + arr[choice]);
                break;
            case 1:
                System.out.print("The value is: " + arr[choice]);
                break;
            case 2:
                System.out.print("The value is: " + arr[choice]);
                break;
            case 3:
                System.out.print("The value is: " + arr[choice]);
                break;
            case 4:
                System.out.print("The value is: " + arr[choice]);
                break;
            case 5:
                System.out.print("The value is: " + arr[choice]);
                break;

            default:
                System.out.println("There have no value.");
                break;
        }
    }
}
