#include <stdio.h>

int main() {
    int num, sum = 0;

    // Start the do-while loop
    do {
        // Ask the user to enter an integer
        printf("Enter an integer (0 to stop): ");
        scanf("%d", &num);

        // If the number is positive, add it to the sum
        if (num > 0) {
            sum += num;
        }

    } while (num != 0);  // Continue until the user enters 0

    // Print the sum of positive integers
    printf("The sum of all positive integers entered is: %d\n", sum);

    return 0;
}
