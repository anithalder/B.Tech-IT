import java.util.Scanner;

class MaxMin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter how many element you want: ");
        int size = sc.nextInt();
        int[] arr = new int[size];

        System.out.print("Enter the space separated array elements: ");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();

        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;

        for (int i = 0; i < size; i++) {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }

        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        sc.close();
    }
}