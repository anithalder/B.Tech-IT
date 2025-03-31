package company;

public class HRDepartment {
    Employee employee;

    HRDepartment(Employee employee) {
        this.employee = employee;
    }

    void showDetails() {
        System.out.println("Name: " + employee.name);
        System.out.println("ID: " + employee.id);
    }
}
