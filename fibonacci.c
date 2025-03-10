#include <stdio.h>

int main() {
    int first = 0, second = 1, next, count = 0;

    printf("First 10 Fibonacci numbers are:\n");

    // Print the first two Fibonacci numbers
    printf("%d\n", first);  // First number
    printf("%d\n", second); // Second number

    count = 2;  // We have already printed the first two numbers

    // Use a while loop to print the next 8 Fibonacci numbers
    while (count < 10) {
        next = first + second;  // Next Fibonacci number
        printf("%d\n", next);    // Print the next Fibonacci number

        first = second;  // Update 'first' to the previous 'second'
        second = next;   // Update 'second' to the new Fibonacci number

        count++;  // Increment the count
    }

    return 0;
}
