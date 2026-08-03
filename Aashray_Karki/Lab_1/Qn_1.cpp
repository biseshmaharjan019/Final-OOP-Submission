// Question 1: Write a C++ program to calculate the perimeter of a rectangle.
// Formula: Perimeter = 2 * (length + width)

#include <iostream>
using namespace std;

int main() {
    int length, width, perimeter;

    cout << "Enter length and width: ";
    cin >> length >> width;

    perimeter = 2 * (length + width);

    cout << "Perimeter of rectangle = " << perimeter << endl;

    return 0;
}