#include <stdio.h>

int main() {
    int number;

    // Ask user to input a number
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the number is even
    if (number % 2 == 0) {
        printf("The number %d is even.\n", number);
    } else {
        printf("The number %d is odd.\n", number);
    }

    return 0;
}

