
import company.Employee;
import company.Finance;

public class EmployeeApp {
    public static void main(String[] args) {
        // Creating two employee objects
        Employee emp1 = new Employee("John Doe", 101, 50000);
        Employee emp2 = new Employee("Alice Smith", 102, 60000);

        // Accessing the salary of the employees
        System.out.println(emp1.name + "'s " + emp1.getSalary(emp1));
        System.out.println(emp2.name + "'s " + emp2.getSalary(emp2));

        // Accessing the employee ID from the Finance group
        Finance finance = new Finance();
        System.out.println(emp1.name + "'s Employee ID: " + finance.getEmployeeId(emp1));
        System.out.println(emp2.name + "'s Employee ID: " + finance.getEmployeeId(emp2));
    }
}
