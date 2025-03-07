package company.group;

import company.Employee;

public class FinanceGroup extends Employee { // Inherit from Employee

    public FinanceGroup(String name, int employeeID, double salary) {
        super(name, employeeID, salary);
    }

    public void showDetails() {
        System.out.println("Employee Name: " + name); // ✅ Public - Accessible
        System.out.println("Employee ID: " + employeeID); // ✅ Protected - Accessible due to inheritance
    }

    public static void main(String[] args) {
        FinanceGroup deptEmp = new FinanceGroup("Anit Halder", 1001, 750000.0);
        deptEmp.showDetails();

        // System.out.println("Salary: " + deptEmp.salary); // ❌ Error - Private member
    }
}