public class Employee {

    protected int id;
    public String name;
    private String mailId;
    String department;

    Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    Employee(String name, int id, String mailId) {
        this.name = name;
        this.id = id;
        this.mailId = mailId;
    }

    Employee(Employee emp, String depatment) {
        this.name = emp.name;
        this.id = emp.id;
        this.mailId = emp.mailId;
        this.department = depatment;
    }

    // Overriding toString method to display employee details
    @Override
    public String toString() {
        return "Name: " + name + ", ID: " + id + ", Mail ID: " + mailId;
    }

    public static void main(String[] args) {
        // Creating Employee objects
        Employee emp1 = new Employee("Alice", 101);
        Employee emp2 = new Employee("Bob", 102, "bob@example.com");

        // Displaying initial details
        System.out.println("Initial Employee Details:");
        System.out.println(emp1);
        System.out.println(emp2);

        // Adding department to emp1
        System.out.println("\nAdding department to Alice:");
        Employee emp3 = new Employee(emp1, "Finance");
        System.out.println(emp3);

    }

}