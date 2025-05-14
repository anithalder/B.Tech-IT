import java.util.Scanner;

public class GeoAreaTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GeoArea geoArea = new GeoArea();

        while (true) {
            System.out.print("1. Rectangle\n2. Square\n3. Circle\n0. Exit\nEnter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter length and width: ");
                    geoArea.setLength(sc.nextDouble());
                    geoArea.setWidth(sc.nextDouble());
                    geoArea.rectangleArea();
                    break;
                case 2:
                    System.out.print("Enter side: ");
                    geoArea.setSide(sc.nextDouble());
                    geoArea.squareArea();
                    break;
                case 3:
                    System.out.print("Enter radius: ");
                    geoArea.setRadius(sc.nextDouble());
                    geoArea.circleArea();
                    break;
                case 0:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            sc.close();
        }
    }
}
