#include <stdio.h>

int main() {
    float height, width, perimeter;

    // Ask user to input height and width of the rectangle
    printf("Enter the height of the rectangle: ");
    scanf("%f", &height);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    // Calculate the perimeter of the rectangle
    perimeter = 2 * (height + width);

    // Display the result
    printf("The perimeter of the rectangle is: %.2f\n", perimeter);

    return 0;
}

