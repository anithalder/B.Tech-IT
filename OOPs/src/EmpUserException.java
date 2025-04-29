import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Employee {
    int id;
    String name;
    long phone;

    Employee(int id, String name, long phone) {
        this.id = id;
        this.name = name;
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Phone: " + phone;
    }
}

public class EmpUserException {
    public static void main(String[] args) {

    }
}
