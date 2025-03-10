#include <stdio.h>

int main() {
    double principal, rate, compoundInterest, amount;
    int time;
    char choice;

    do {
        // Ask the user for the principal amount, interest rate, and time period
        printf("Enter the principal amount: ");
        scanf("%lf", &principal);

        printf("Enter the interest rate (in %%): ");
        scanf("%lf", &rate);

        printf("Enter the time period (in years): ");
        scanf("%d", &time);

        // Calculate the compound interest using the formula: A = P * (1 + R/100)^T
        amount = principal * (1 + rate / 100); // Calculate (1 + R/100)
        
        // Calculate compound interest by raising the amount to the power of time
        for (int i = 1; i < time; i++) {
            amount *= (1 + rate / 100);  // Multiply by (1 + R/100) for each year
        }

        // Compound interest is the amount minus the principal
        compoundInterest = amount - principal;

        // Display the result
        printf("The compound interest is: %.2lf\n", compoundInterest);

        // Ask if the user wants to calculate again
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &choice);  // Note: the space before %c is to consume any leftover newline character from the previous input

    } while (choice == 'y' || choice == 'Y');  // Continue if user enters 'y' or 'Y'

    printf("Thank you for using the Compound Interest Calculator.\n");

    return 0;
}
