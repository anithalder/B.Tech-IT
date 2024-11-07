#include <stdio.h>
#include <stdint.h>

// Helper function to convert an 8-bit integer to its binary representation
void printBinary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int8_t signed_multiply_8bit(int8_t a, int8_t b) {
    int32_t result = 0;
    int8_t sign = (a < 0) ^ (b < 0) ? -1 : 1;
    uint8_t pos_a = a < 0 ? (uint8_t)(-a) : (uint8_t)a;
    uint8_t pos_b = b < 0 ? (uint8_t)(-b) : (uint8_t)b;

    printf("Multiplication Steps:\n");
    printf("---------------------\n");
    printf("Multiplier (b): %d (0x%02X) ", b, pos_b);
    printBinary(pos_b);
    printf("\n");
    printf("Multiplicand (a): %d (0x%02X) ", a, pos_a);
    printBinary(pos_a);
    printf("\n");
    printf("---------------------\n");
    printf("N | Multiplier Bit | Multiplicand (a) | Action       | Accumulator (result)\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < 8; i++) {
        printf("%d | ", i + 1);
        printf("%d                | ", (pos_b >> i) & 1);
        printBinary(pos_a);
        printf("          | ");
        if ((pos_b >> i) & 1) {
            result += pos_a;
            printf("Add          | 0x%04X\n", result);
        } else {
            printf("No Action    | 0x%04X\n", result);
        }
        pos_a <<= 1;
    }

    printf("---------------------\n");
    result = (int8_t)(sign * result);
    printf("Final Result (8-bit): %d (0x%02X) ", result, result);
    printBinary((uint8_t)result); //Print the final result in binary
    printf("\n");
    return result;
}

int main() {
    int8_t multiplicand = -91;
    int8_t multiplier = 27;
    int8_t product = signed_multiply_8bit(multiplicand, multiplier);
    printf("The product of %d and %d is: %d\n", multiplicand, multiplier, product);
    return 0;
}