package company.hr;

import company.Employee;

public class HRDepartment {
    private Employee employee;

    public HRDepartment(Employee employee) {
        this.employee = employee;
    }

    public void showId() {
        employee.showId();
    }
}
