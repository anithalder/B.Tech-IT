package company;

public class Employee {
    // private: accessible only within the same class
    private double salary;

    // protected: accessible within the same package and subclasses
    protected int id;

    // public: accessible from any other class
    public String name;

    Employee(String name, double salary, int id) {
        this.name = name;
        this.salary = salary;
        this.id = id;
    }

    void showSalary() {
        System.out.println("Salary: " + salary);
    }
}
