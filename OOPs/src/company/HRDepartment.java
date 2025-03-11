package company;

public class HRDepartment {
    Employee employee;

    HRDepartment(Employee employee) {
        this.employee = employee;
    }

    void showId() {
        System.out.println("ID: " + employee.id);
    }
}
