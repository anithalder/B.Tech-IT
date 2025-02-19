#include <stdio.h>

#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

// Function Prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

void main()
{
    int which;
    double param1, param2, result = 0; // Initialize result
    char *operationName;               // String to store operation name

    // Prompt user for operation
    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter the operation number: ");
    scanf("%d", &which);

    // Get input values
    printf("Enter the first parameter: ");
    scanf("%lf", &param1);

    printf("Enter the second parameter: ");
    scanf("%lf", &param2);

    // Perform the selected operation
    switch (which)
    {
    case ADDITION:
        result = add(param1, param2);
        operationName = "Addition";
        break;
    case SUBTRACTION:
        result = subtract(param1, param2);
        operationName = "Subtraction";
        break;
    case MULTIPLICATION:
        result = multiply(param1, param2);
        operationName = "Multiplication";
        break;
    case DIVISION:
        if (param2 == 0)
        {
            printf("Error: Division by zero is not allowed!\n");
            return 1; // Exit program with error
        }
        result = divide(param1, param2);
        operationName = "Division";
        break;
    default:
        printf("Invalid operation\n");
        return 1; // Exit program on invalid input
    }

    // Print result with operation name
    printf("Operation: %s on %.2f and %.2f, result is %.2f\n", operationName, param1, param2, result);

    return 0;
}

// Function Definitions
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
