import company.Employee;
import company.finance.FinanceDepartment;
import company.general.GeneralAccess;
import company.hr.HRDepartment;

public class EmployeeApp {

    public static void main(String[] args) {
        Employee employee = new Employee("John Doe", 50000, 123);
        // System.out.println("Name: " + employee.name);
        // System.out.println("Salary: " + employee.getSalary());

        // Create an instance of FinanceDepartment
        FinanceDepartment finance = new FinanceDepartment("John Doe", 50000, 123);
        finance.showDetails();
        System.out.println();
        // Create an instance of HRDepartment
        HRDepartment hr = new HRDepartment("Jane Doe", 60000, 456);
        hr.showId();
        System.out.println();
        // Create an instance of GeneralAccess
        GeneralAccess general = new GeneralAccess();
        general.showName(employee);
    }
}