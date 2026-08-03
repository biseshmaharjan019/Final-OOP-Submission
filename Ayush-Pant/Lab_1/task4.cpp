#include <iostream>
using namespace std;

float calculateArea(float length, float width) {
    return length * width;
}

float calculatePerimeter(float length, float width) {
    return 2 * (length + width);
}

int main() {
    float length, width;

    cout << "Enter length of the rectangle: ";
    cin >> length;
    cout << "Enter width of the rectangle: ";
    cin >> width;

    cout << "Area of the rectangle = " << calculateArea(length, width) << endl;
    cout << "Perimeter of the rectangle = " << calculatePerimeter(length, width) << endl;

    return 0;
}
