import company.Employee;

public class EmployeeApp {
    public static void main(String[] args) {
        Employee emp = new Employee("Alice Smith", 2002, 85000.0);

        System.out.println("Employee Name: " + emp.name + "Salary: $" + emp.showSalary()); // ✅ Public - Accessible
    }
}