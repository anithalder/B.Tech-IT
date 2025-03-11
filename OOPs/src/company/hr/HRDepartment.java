package company.hr;

import company.Employee;
import company.Employee.*;

public class HRDepartment extends Employee {
    public HRDepartment(String name, double salary, int id) {
        super(name, salary, id);
    }

    public void showId() {
        System.out.println("ID: " + id);
    }
}
