import java.util.ArrayList;
import java.util.List;

// Base Employee class
class Employee {
    protected static int totalEmployees = 0;

    protected int id;
    protected String name;
    private String mailId;
    protected String department;
    protected String degree;

    public Employee(String name, int id, String degree) {
        this.name = name;
        this.id = id;
        this.degree = degree;
        totalEmployees++;
    }

    // Setters and getters
    public void setMailId(String mailId) {
        this.mailId = mailId;
    }

    public String getMailId() {
        return mailId;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public static int getTotalEmployees() {
        return totalEmployees;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Degree: " + degree +
                ", Dept: " + department + ", Email: " + mailId;
    }
}

// Manager class (extends Employee)
class Manager extends Employee {
    private static int totalManagers = 0;
    private int yearsOfExperience;

    public Manager(String name, int id, String degree, int yearsOfExperience) {
        super(name, id, degree);
        this.yearsOfExperience = yearsOfExperience;
        totalManagers++;
    }

    public static int getTotalManagers() {
        return totalManagers;
    }

    public int getYearsOfExperience() {
        return yearsOfExperience;
    }

    @Override
    public String toString() {
        return super.toString() + ", Role: Manager, Exp: " + yearsOfExperience + " yrs";
    }
}

// Supervisor class (extends Employee directly)
class Supervisor extends Employee {
    private static int totalSupervisors = 0;
    private String officeHours;

    public Supervisor(String name, int id, String degree, String officeHours) {
        super(name, id, degree);
        this.officeHours = officeHours;
        totalSupervisors++;
    }

    public static int getTotalSupervisors() {
        return totalSupervisors;
    }

    public String getOfficeHours() {
        return officeHours;
    }

    @Override
    public String toString() {
        return super.toString() + ", Role: Supervisor, Hours: " + officeHours;
    }
}

// Main class to test the hierarchy
public class CompanyDB {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<>();

        // Create employees
        Employee emp1 = new Employee("John Doe", 1001, "Bachelor's");
        // emp1.setMailId("john@company.com");
        // emp1.setDepartment("Engineering");

        Manager mgr1 = new Manager("Jane Smith", 2001, "MBA", 8);
        mgr1.setMailId("jane@company.com");
        mgr1.setDepartment("Marketing");

        Supervisor sup1 = new Supervisor("Mike Brown", 3001, "Associate's", "9AM-5PM");
        sup1.setMailId("mike@company.com");
        sup1.setDepartment("Operations");

        // Add to list
        employees.add(emp1);
        employees.add(mgr1);
        employees.add(sup1);

        // Display all employees
        System.out.println("=== COMPANY STAFF ===");
        employees.forEach(System.out::println);

        // Display counts
        System.out.println("\n=== EMPLOYEE COUNTS ===");
        System.out.println("Total Employees: " + Employee.getTotalEmployees());
        System.out.println("Managers: " + Manager.getTotalManagers());
        System.out.println("Supervisors: " + Supervisor.getTotalSupervisors());
    }
}