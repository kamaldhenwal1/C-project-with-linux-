#include <stdio.h>

int main() {
    int num1, num2, num3, num4, num5;

    // Input five numbers
    printf("Enter five numbers: ");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    // Find the largest number using nested if
    if (num1 >= num2) {
        if (num1 >= num3) {
            if (num1 >= num4) {
                if (num1 >= num5) {
                    printf("The largest number is: %d\n", num1);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            } else {
                if (num4 >= num5) {
                    printf("The largest number is: %d\n", num4);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            }
        } else {
            if (num3 >= num4) {
                if (num3 >= num5) {
                    printf("The largest number is: %d\n", num3);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            } else {
                if (num4 >= num5) {
                    printf("The largest number is: %d\n", num4);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            }
        }
    } else {
        if (num2 >= num3) {
            if (num2 >= num4) {
                if (num2 >= num5) {
                    printf("The largest number is: %d\n", num2);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            } else {
                if (num4 >= num5) {
                    printf("The largest number is: %d\n", num4);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            }
        } else {
            if (num3 >= num4) {
                if (num3 >= num5) {
                    printf("The largest number is: %d\n", num3);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            } else {
                if (num4 >= num5) {
                    printf("The largest number is: %d\n", num4);
                } else {
                    printf("The largest number is: %d\n", num5);
                }
            }
        }
    }

    return 0;
}
