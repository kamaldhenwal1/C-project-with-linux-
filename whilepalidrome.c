#include <stdio.h>

int main() {
    int num, reversedNum = 0, originalNum, remainder;

    // Ask the user to input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num; // Store the original number to compare later

    // Reverse the digits of the number using a while loop
    while (num != 0) {
        remainder = num % 10;             // Get the last digit
        reversedNum = reversedNum * 10 + remainder; // Add the digit to the reversed number
        num /= 10;                        // Remove the last digit from num
    }

    // Check if the original number is equal to the reversed number
    if (originalNum == reversedNum) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }
    return 0;
}
