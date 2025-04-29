import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Custom exception for ID validation
class InvalidIDException extends Exception {
    public InvalidIDException(String message) {
        super(message);
    }
}

// Custom exception for Name validation
class InvalidNameException extends Exception {
    public InvalidNameException(String message) {
        super(message);
    }
}

// Custom exception for Phone validation
class InvalidPhoneException extends Exception {
    public InvalidPhoneException(String message) {
        super(message);
    }
}

// Custom exception for Field Sequence Validation
class InvalidFieldSequenceException extends Exception {
    public InvalidFieldSequenceException(String message) {
        super(message);
    }
}

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
        Scanner sc = new Scanner(System.in);
        ArrayList<Employee> employees = new ArrayList<Employee>(); // Employee list
        List<String> errors = new ArrayList<>(); // Collect errors during validation

        System.out.println("Enter Employee data in the format {id, name, phone, id, name, phone, ...}: ");
        String input = sc.nextLine();

        input = input.replace("{", "").replace("}", "");
        String[] parts = input.split(",\\s*");

        // Validate the field sequence
        validateFieldSequence(parts, errors);

        // Validate each employee's fields
        for (int i = 0; i < parts.length; i += 3) {
            try {
                // Validate ID
                int id = validateID(parts[i]);
            } catch (InvalidIDException e) {
                errors.add("Employee " + (i / 3 + 1) + ": ID " + e.getMessage());
            }

            try {
                // Validate Name
                String name = validateName(parts[i + 1].trim());
            } catch (InvalidNameException e) {
                errors.add("Employee " + (i / 3 + 1) + ": Name " + e.getMessage());
            }

            try {
                // Validate Phone
                long phone = validatePhone(parts[i + 2]);
            } catch (InvalidPhoneException e) {
                errors.add("Employee " + (i / 3 + 1) + ": Phone " + e.getMessage());
            }
        }

        // Check if any errors were found
        if (!errors.isEmpty()) {
            // Display collected errors
            System.out.println("\nErrors Found:");
            for (String error : errors) {
                System.out.println(error);
            }
            sc.close();
            return; // Exit the program if errors are found
        }

        // If no errors, proceed to ask for the index
        System.out.print("Input an index (starting from 1): ");
        int index = sc.nextInt();

        try {
            // Validate the index before accessing the array
            if (index < 1 || index > employees.size()) {
                System.out
                        .println("Invalid index! Please enter an index between 1 and " + (employees.size() + 1) + ".");
            } else {
                System.out.println("Employee at index " + index + ": " + employees.get(index - 1));
            }
        } catch (Exception e) {
            System.out.println("An error occurred while retrieving the employee: " + e.getMessage());
        }

        sc.close();
    }

    // Method to validate ID
    private static int validateID(String idStr) throws InvalidIDException {
        try {
            int id = Integer.parseInt(idStr);
            if (id < 100 || id > 999) {
                throw new InvalidIDException("must be a 3-digit integer.");
            }
            return id;
        } catch (NumberFormatException e) {
            throw new InvalidIDException("must be a valid integer.");
        }
    }

    // Method to validate Name
    private static String validateName(String name) throws InvalidNameException {
        if (!name.matches("[a-zA-Z]+")) {
            throw new InvalidNameException("must contain only alphabetic characters.");
        }
        return name;
    }

    // Method to validate Phone
    private static long validatePhone(String phoneStr) throws InvalidPhoneException {
        try {
            long phone = Long.parseLong(phoneStr);
            if (phone < 10000 || phone > 99999) {
                throw new InvalidPhoneException("must be a 5-digit integer.");
            }
            return phone;
        } catch (NumberFormatException e) {
            throw new InvalidPhoneException("must be a valid integer.");
        }
    }

    // Method to validate field sequence
    private static void validateFieldSequence(String[] parts, List<String> errors) {
        for (int i = 0; i < parts.length; i++) {
            if (i % 3 == 0) { // ID field
                try {
                    Integer.parseInt(parts[i]);
                } catch (NumberFormatException e) {
                    errors.add("Invalid sequence: Expected an ID at position " + (i + 1));
                }
            } else if (i % 3 == 1) { // Name field
                if (!parts[i].matches("[a-zA-Z]+")) {
                    errors.add("Invalid sequence: Expected a Name at position " + (i + 1));
                }
            } else if (i % 3 == 2) { // Phone field
                try {
                    Long.parseLong(parts[i]);
                } catch (NumberFormatException e) {
                    errors.add("Invalid sequence: Expected a Phone at position " + (i + 1));
                }
            }
        }
    }
}
