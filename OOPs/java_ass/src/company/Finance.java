package company;

public class Finance {
    public int getEmployeeId(Employee emp) {
        return emp.empId; // Allowed: Finance is in the same package as Employee
    }
}
