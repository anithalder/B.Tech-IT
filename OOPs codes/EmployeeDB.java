public class EmployeeDB {
    protected String name;
    protected int id;
    private String email;
    private double salary;
    static final String companyName = "TCS";

    public void setEmail(String email) {
        this.email = email;
    }

    protected void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    protected void setSalary(double salary) {
        this.salary = salary;
    }

    public static String getCompanyname() {
        return companyName;
    }

    public String getEmail() {
        return email;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    protected double getSalary() {
        return salary;
    }

    public String toString() {
        return "Name: " + name + ", ID: " + id + ", Email: " + email + ", Salary: " + salary;
    }
}
