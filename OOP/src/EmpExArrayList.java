import java.util.Scanner;
import java.util.ArrayList;
import java.lang.reflect.Field;

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

public class EmpExArrayList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Employee> employees = new ArrayList<>();

        try {
            Field[] fields = Employee.class.getDeclaredFields();
            int requiredFields = fields.length;

            System.out.println("Note: Each employee requires " + requiredFields + " fields (id, name, phone).");
            System.out.println("Enter data in format {id,name,phone,id,name,phone...}: ");

            String input = sc.nextLine();

            // Check for empty input
            if (input.trim().isEmpty()) {
                System.out.println("Error: No input provided");
                return;
            }

            String[] parts = input.replace("{", "").replace("}", "").split(",\\s*");

            // This will automatically throw ArrayIndexOutOfBoundsException if parts.length
            // % requiredFields != 0
            for (int i = 0; i < parts.length; i += requiredFields) {
                employees.add(new Employee(
                        Integer.parseInt(parts[i]),
                        parts[i + 1].trim(),
                        Long.parseLong(parts[i + 2])));
            }

            System.out.print("Enter index (1-based): ");
            int index = sc.nextInt();

            // This will automatically throw IndexOutOfBoundsException for invalid index
            System.out.println("Employee: " + employees.get(index - 1));

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Incomplete employee data. Each employee requires 3 fields (id, name, phone)");
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid number format in input");
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Error: Invalid index. Please enter a number between 1 and " + employees.size());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}