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

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    cout << "Area = " << calculateArea(length, width) << endl;
    cout << "Perimeter = " << calculatePerimeter(length, width) << endl;

    return 0;
}
