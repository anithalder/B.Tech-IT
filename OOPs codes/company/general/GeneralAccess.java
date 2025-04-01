package company.general;

import company.Employee;

public class GeneralAccess {
    Employee employee;

    public GeneralAccess(Employee employee) {
        this.employee = employee;
    }

    public void showDetails() {
        System.out.println("Name: " + employee.name);
    }
}
