#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    // Display the menu options to the user
    printf("Menu-Driven Calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");

    // Keep the menu running until the user chooses to exit
    do {
        // Ask the user for the choice
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            // Input two numbers for calculation
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (choice) {
            case 1:  // Addition
                result = num1 + num2;
                printf("The result of addition is: %.2f\n", result);
                break;
            case 2:  // Subtraction
                result = num1 - num2;
                printf("The result of subtraction is: %.2f\n", result);
                break;
            case 3:  // Multiplication
                result = num1 * num2;
                printf("The result of multiplication is: %.2f\n", result);
                break;
            case 4:  // Division
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("The result of division is: %.2f\n", result);
                } else {
                    printf("Error! Division by zero is not allowed.\n");
                }
                break;
            case 5:  // Exit
                printf("Exiting the program.\n");
                break;
            default:  // Invalid choice
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0;
}
