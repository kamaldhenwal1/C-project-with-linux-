#include <stdio.h>

int main() {
    int num, i = 0, numbers[100], isDuplicate;
    
    // Initialize the array to store entered numbers
    printf("Enter numbers (input a duplicate to stop):\n");

    while (1) {
        // Read user input
        printf("Enter a number: ");
        scanf("%d", &num);

        // Check for duplicates
        isDuplicate = 0;  // Assume it's not a duplicate
        
        // Loop through the previously entered numbers to check for a duplicate
        for (int j = 0; j < i; j++) {
            if (numbers[j] == num) {
                isDuplicate = 1;  // A duplicate was found
                break;
            }
        }

        if (isDuplicate) {
            printf("Duplicate number entered: %d. Exiting...\n", num);
            break;  // Exit the loop if a duplicate is found
        } else {
            // Store the entered number in the array
            numbers[i] = num;
            i++;  // Increment the count of entered numbers
        }
    }

    return 0;
}
