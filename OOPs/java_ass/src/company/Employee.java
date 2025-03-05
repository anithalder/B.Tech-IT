package company;

import java.util.Random;

public class Employee {
    public String name; // Public: Accessible by anyone
    protected int empId; // Protected: Accessible by the company or subclasses
    private double salary; // Private: Only accessible by the same Employee object

    public Employee(String name, int empId, double salary) {
        this.name = name;
        this.empId = (empId <= 0) ? new Random().nextInt(1000) : empId;
        this.salary = salary;
    }

    // Getter method for the employee to check their own salary
    public double getSalary(Employee requester) {
        // Check if the requester is the same employee
        if (this == requester) {
            return this.salary;
        } else {
            throw new SecurityException("Access denied: You can only access your own salary.");
        }
    }

    // Method to allow to access the salary
    void getSalary() {
        System.out.println("Salary: ₹" + salary);
    }
}

// Employee salary can be access by the same employee member
// Employee name can be access by anyone
// Employee ID can be access by another group in same company