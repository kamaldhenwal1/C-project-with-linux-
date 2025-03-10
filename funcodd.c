#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }
}

int main() {
    int number;

    // Ask the user to input a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the function to check if the number is even or odd
    checkEvenOdd(number);

    return 0;
}
