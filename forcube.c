#include <stdio.h>

int main() {
    int n;

    // Ask the user to input the value of n
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Display the cube of numbers from 1 to n
    printf("Cube of numbers from 1 to %d are:\n", n);
    
    for (int i = 1; i <= n; i++) {
        printf("Cube of %d = %d\n", i, i * i * i);
    }

    return 0;
}
