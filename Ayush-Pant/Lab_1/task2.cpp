#include <iostream>
using namespace std;

int main() {
    float length, width, perimeter;

    cout << "Enter length of the rectangle: ";
    cin >> length;
    cout << "Enter width of the rectangle: ";
    cin >> width;

    perimeter = 2 * (length + width);
    cout << "Perimeter of the rectangle = " << perimeter << endl;

    return 0;
}
