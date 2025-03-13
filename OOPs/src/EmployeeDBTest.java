import java.util.Scanner;

public class EmployeeDBTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EmployeeDB[] employees = new EmployeeDB[3];

        for (int i = 0; i < employees.length; i++) {
            employees[i] = new EmployeeDB();
            System.out.println("\nEnter details for Employee " + (i + 1) + ":");

            System.out.print("Name: ");
            sc.nextLine(); // Consume newline left from previous input
            employees[i].setName(sc.nextLine());

            System.out.print("Email: ");
            employees[i].setEmail(sc.next());

            System.out.print("ID: ");
            employees[i].setId(sc.nextInt());

            System.out.print("Salary: ");
            employees[i].setSalary(sc.nextDouble());
        }

        System.out.println("\nEmployee Details:");
        for (EmployeeDB employee : employees) {
            System.out.println(employee);
        }

        sc.close();
    }
}
