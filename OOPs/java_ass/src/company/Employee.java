package company;

public class Employee {
    private double salary;
    protected int id;
    public String name;

    public Employee(String name, double salary, int id) {
        this.name = name;
        this.salary = salary;
        this.id = id;
    }

    protected double getSalary() {
        return salary;
    }
}
