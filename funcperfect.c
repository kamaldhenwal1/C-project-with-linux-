#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of the series
float sumOfSeries() {
    float sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        sum += (float)factorial(i) / i; // Calculate factorial(i) / i
    }
    return sum;
}

int main() {
    // Calculate and display the sum of the series
    float result = sumOfSeries();
    printf("The sum of the series is: %.2f\n", result);
    
    return 0;
}
