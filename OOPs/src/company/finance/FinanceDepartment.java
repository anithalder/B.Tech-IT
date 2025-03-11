package company.finance;

import company.Employee;

public class FinanceDepartment {
    Employee employee;

    public FinanceDepartment(Employee employee) {
        this.employee = employee;
    }

    public void showDetails() {
        System.out.println("Name: " + employee.name);
        employee.showId();
        employee.showSalary();
    }
}
