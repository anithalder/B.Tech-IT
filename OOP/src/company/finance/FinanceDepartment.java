package company.finance;

import company.Employee;

public class FinanceDepartment extends Employee {
    public FinanceDepartment(String name, double salary, int id) {
        super(name, salary, id);
    }

    public void showDetails() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Salary: " + getSalary());
    }
}
