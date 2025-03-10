#include <stdio.h>

int main() {
    int num, count = 0;
    float sum = 0.0, average;
    char choice;

    do {
        // Ask the user to input a number
        printf("Enter a number: ");
        scanf("%d", &num);

        // Add the number to the sum and increase the count
        sum += num;
        count++;

        // Ask the user if they want to continue
        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to capture the newline character

    } while (choice == 'y' || choice == 'Y');  // Continue if user enters 'y' or 'Y'

    // Check if at least one number was entered
    if (count > 0) {
        // Calculate the average
        average = sum / count;
        printf("The average of the entered numbers is: %.2f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}
