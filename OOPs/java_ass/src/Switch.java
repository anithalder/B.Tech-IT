import java.util.Scanner;

class Switch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = { 1, 2, 3, 4, 5 };
        int n = arr.length;
        int choice;

        System.out.print("Enter any choice between " + 0 + " to " + n + ": ");
        switch (choice = sc.nextInt()) {
            case 1:
                System.out.println("Value is:" + arr[choice]);
                break;
            case 2:
                System.out.println("Value is:" + arr[choice]);
                break;
            case 3:
                System.out.println("Value is:" + arr[choice]);
                break;
            case 4:
                System.out.println("Value is:" + arr[choice]);
                break;
            case 5:
                System.out.println("Value is:" + arr[choice]);
                break;

            default:
                System.out.println("Value is: " + arr[choice]);
                break;
        }

        sc.close();
    }
}
