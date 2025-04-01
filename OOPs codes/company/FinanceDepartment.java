package company;

public class FinanceDepartment {
    Employee employee;

    FinanceDepartment(Employee employee) {
        this.employee = employee;
    }

    void showDetails() {
        System.out.println("Name: " + employee.name);
        System.out.println("ID: " + employee.id);
        employee.showSalary();
    }
}
