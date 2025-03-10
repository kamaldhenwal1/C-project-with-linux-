#include <stdio.h>

int main() {
    int angle1, angle2, angle3;

    // Input the angles of the triangle
    printf("Enter the first angle: ");
    scanf("%d", &angle1);
    printf("Enter the second angle: ");
    scanf("%d", &angle2);
    printf("Enter the third angle: ");
    scanf("%d", &angle3);

    // Check if the sum of angles is equal to 180 and all angles are positive
    if (angle1 > 0 && angle2 > 0 && angle3 > 0 && (angle1 + angle2 + angle3 == 180)) {
        printf("The angles form a valid triangle.\n");
    } else {
        printf("The angles do not form a valid triangle.\n");
    }

    return 0;
}
