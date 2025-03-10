
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }

    for (int i = 2; i * i <= num; i++) {  // We only need to check up to the square root of the number
        if (num % i == 0) {
            return 0;  // If num is divisible by any number other than 1 and itself, it's not prime
        }
    }

    return 1;  // If no divisors were found, the number is prime
}

int main() {
    int number;

    // Ask the user for input
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is prime using the isPrime function
    if (isPrime(number) == 1) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
