//1. Write a C program to calculate the perimeter of a rectangle (2 * (length + width)).
#include <stdio.h>

int main() {
    float l, w, p;

    printf("Enter length and width: ");
    scanf("%f %f", &l,&w);

    p= 2 * (l + w);

    printf("Perimeter of rectangle = %.2f", p);

    return 0;
}