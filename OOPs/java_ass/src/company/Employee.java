// Employee salary can be access by the same employee member
// Employee name can be access by anyone
// Employee ID can be access by another group in same company

package company;

public class Employee {
    public String name; // Can be accessed by anyone
    protected int employeeID; // Can be accessed within same package & subclasses
    private double salary; // Can be accessed only within this class

    public Employee(String name, int employeeID, double salary) {
        this.name = name;
        this.employeeID = employeeID;
        this.salary = salary;
    }

    // Method to allow only the employee to access salary
    public double showSalary() {
        return salary;
    }
}