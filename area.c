#include <stdio.h>
#include <math.h>  // For mathematical functions like pow and sqrt

#define PI 3.14159

int main() {
    int choice;
    float radius, side, length, width, base, height, area;

    // Display the menu to the user
    printf("Menu-Driven Area Calculator\n");
    printf("1. Area of Circle\n");
    printf("2. Area of Square\n");
    printf("3. Area of Rectangle\n");
    printf("4. Area of Triangle\n");
    printf("5. Exit\n");

    do {
        // Ask the user for the choice
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Calculate the area of a circle
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                area = PI * radius * radius;
                printf("The area of the circle is: %.2f\n", area);
                break;

            case 2:
                // Calculate the area of a square
                printf("Enter the side length of the square: ");
                scanf("%f", &side);
                area = side * side;
                printf("The area of the square is: %.2f\n", area);
                break;

            case 3:
                // Calculate the area of a rectangle
                printf("Enter the length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                area = length * width;
                printf("The area of the rectangle is: %.2f\n", area);
                break;

            case 4:
                // Calculate the area of a triangle
                printf("Enter the base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                area = 0.5 * base * height;
                printf("The area of the triangle is: %.2f\n", area);
                break;

            case 5:
                // Exit the program
                printf("Exiting the program.\n");
                break;

            default:
                // Handle invalid choices
                printf("Invalid choice! Please select a valid option (1-5).\n");
        }
    } while (choice != 5); // Repeat the menu until the user chooses to exit

    return 0;
}
