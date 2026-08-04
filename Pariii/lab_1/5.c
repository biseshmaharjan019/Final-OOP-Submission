//5. Write a C program to print the sum of numbers from 1 to 5 using a for loop.
#include <stdio.h>

int main() {
    int i, sum = 0;

    for(i = 1; i <= 5; i++) {
        sum = sum + i;
    }

    printf("Sum of numbers from 1 to 5 = %d", sum);

    return 0;
}