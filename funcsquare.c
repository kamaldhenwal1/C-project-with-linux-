#include <stdio.h>

// Function to calculate the square of a number
int square(int num) {
    return num * num;  // Return the square of the number
}

int main() {
    int number;

    // Ask the user to input a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the function to find the square
    int result = square(number);

    // Display the result
    printf("The square of %d is: %d\n", number, result);

    return 0;
}




