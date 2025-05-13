import java.util.Scanner;

public class EmployeeFileTest {

    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nChoose an option:");
            System.out.println("1. Add Employee Details");
            System.out.println("2. Delete Employee Details");
            System.out.println("3. Update Employee Details");
            System.out.println("4. Show All Employee Details");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    EmployeeFile.addEmployee();
                    break;

                case 2:
                    System.out.println("Delete Employee Details functionality is not implemented yet.");
                    // Add logic to delete employee details
                    break;

                case 3:
                    System.out.println("Update Employee Details functionality is not implemented yet.");
                    // Add logic to update employee details
                    break;

                case 4:
                    EmployeeFile.showAllEmployee();
                    break;

                case 5:
                    System.out.println("Exiting the program.");
                    System.exit(choice);
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
