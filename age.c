#include <stdio.h>

int main() {
    int age;

    // Ask the user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the candidate is eligible to vote
    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
    }

    return 0;
}

