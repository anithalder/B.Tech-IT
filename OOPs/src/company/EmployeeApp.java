package company;

import company.general.GeneralAccess;

public class EmployeeApp {

    public static void main(String[] args) {
        Employee employee = new Employee("John Doe", 50000, 123);

        // Create an instance of FinanceDepartment
        System.out.println("Finance Department");
        FinanceDepartment finance = new FinanceDepartment(employee);
        finance.showDetails();

        System.out.println();

        // Create an instance of HRDepartment
        System.out.println("HR Department");
        HRDepartment hr = new HRDepartment(employee);
        System.out.println("Name: " + employee.name);
        hr.showId();

        System.out.println();

        // Create an instance of GeneralAccess
        System.out.println("General Access");
        GeneralAccess general = new GeneralAccess();
        general.showName(employee);
    }
}