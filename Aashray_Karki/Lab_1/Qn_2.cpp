// Question 2: Calculate both area and perimeter using two separate functions in C++.

#include <iostream>
using namespace std;

int calculateArea(int length, int width) {
    return length * width;
}

int calculatePerimeter(int length, int width) {
    return 2 * (length + width);
}

int main() {
    int length, width;

    cout << "Enter length and width: ";
    cin >> length >> width;

    cout << "Area of rectangle = " << calculateArea(length, width) << endl;
    cout << "Perimeter of rectangle = " << calculatePerimeter(length, width) << endl;

    return 0;
}