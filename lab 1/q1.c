#include <stdio.h>

int main()
{
    float length, width, perimeter;

    printf("Enter length: ");
    scanf("%f", &length);

    printf("Enter width: ");
    scanf("%f", &width);

    perimeter = 2 * (length + width);

    printf("Perimeter = %.2f", perimeter);

    return 0;
}
