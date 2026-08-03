#include <stdio.h>

float area(float l, float w)
{
    return l * w;
}

float perimeter(float l, float w)
{
    return 2 * (l + w);
}

int main()
{
    float length, width;

    printf("Enter length: ");
    scanf("%f", &length);

    printf("Enter width: ");
    scanf("%f", &width);

    printf("Area = %.2f\n", area(length, width));
    printf("Perimeter = %.2f", perimeter(length, width));

    return 0;
}
