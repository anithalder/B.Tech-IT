package company;

public class FinanceGroup {
    public int getEmployeeId(Employee emp) {
        return emp.empId; // Allowed: Finance is in the same package as Employee
    }
}
