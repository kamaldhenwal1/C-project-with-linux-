#include <stdio.h>

int main() {
    int m, n;

    // Reading the value of m
    printf("Enter an integer: ");
    scanf("%d", &m);

    // Checking the value of m and setting n accordingly
    if (m > 0) {
        n = 1;
    } else if (m == 0) {
        n = 0;
    } else {
        n = -1;
    }

    // Displaying the value of n
    printf("The value of n is: %d\n", n);

    return 0;
}
