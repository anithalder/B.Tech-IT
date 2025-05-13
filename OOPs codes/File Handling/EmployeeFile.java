import java.util.Scanner;
import java.io.*;

public class EmployeeFile {

    static String FILE_NAME = "employee.txt";
    static String FILE_PATH = "C:\\Users\\User\\Documents\\" + FILE_NAME;

    // Method to create a new employee file
    public static void addEmployee() {
        Scanner scanner = new Scanner(System.in);
        try (FileWriter fileWriter = new FileWriter(FILE_NAME, true)) {
            System.out.print("Enter employee name: ");
            String name = formatName(scanner.nextLine());
            System.out.print("Enter employee Address: ");
            String address = scanner.nextLine();
            System.out.print("Enter employee Phone No.: ");
            String phoneNo = scanner.nextLine();

            // Validate phone number
            while (!validatePhoneNumber(phoneNo)) {
                System.out.print("Invalid phone number. Please enter a valid 10-digit phone number: ");
                phoneNo = scanner.nextLine();
            }

            fileWriter.write("" + "Name: " + name + ", Address: " + address + ", Phone No.: " + phoneNo + "\n");
            System.out.println("Employee details added successfully.");

        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }

    public static String formatName(String name) {
        String[] parts = name.split(" ");
        StringBuilder formattedName = new StringBuilder();

        if (!name.matches("[a-zA-Z]+")) {
            System.out.println("Name is invalid.");
            return null;
        }

        for (String part : parts) {
            if (formattedName.length() > 0) {
                formattedName.append(" ");
            }
            formattedName.append(part.substring(0, 1).toUpperCase()).append(part.substring(1).toLowerCase());
        }

        return formattedName.toString();
    }

    public static boolean validatePhoneNumber(String phoneNo) {
        // Assuming a valid phone number is 10 digits long
        // and contains only digits
        return phoneNo.matches("\\d{10}");
    }

    // Method to read the employee file
    public static void showAllEmployee() {
        File file = new File(FILE_NAME);
        if (!file.exists()) {
            System.out.println("The file does not exist.");
            return;
        }

        try (Scanner fileScanner = new Scanner(file)) {
            System.out.println("Employee Details:");
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                System.out.println(line);
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }

    public static void updateEmployee() {

    }

    public static void deleteEmployee() {
        File file = new File(FILE_NAME);
        if (!file.exists()) {
            System.out.println("The file does not exist.");
            return;
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the name of the employee to delete: ");
        String targetName = scanner.nextLine();

        File tempFile = new File("temp_" + FILE_NAME);
        boolean found = false;

        try (Scanner fileScanner = new Scanner(file);
                FileWriter writer = new FileWriter(tempFile)) {

            while (fileScanner.hasNextLine()) {
                String currentLine = fileScanner.nextLine();

                if (currentLine.contains("Name: " + targetName + ",")) {
                    found = true;
                    System.out.println("Employee details deleted: " + currentLine);
                    // Skip writing this line to the temp file
                } else {
                    writer.write(currentLine + "\n");
                }
            }

        } catch (IOException e) {
            System.out.println("An error occurred while deleting the employee: " + e.getMessage());
        }

        if (found) {
            // Replace the original file with the updated file
            if (file.delete() && tempFile.renameTo(file)) {
                System.out.println("Employee deleted successfully.");
            } else {
                System.out.println("An error occurred while replacing the file.");
            }
        } else {
            System.out.println("Employee with the name '" + targetName + "' not found.");
            tempFile.delete(); // Clean up temporary file
        }
    }

}