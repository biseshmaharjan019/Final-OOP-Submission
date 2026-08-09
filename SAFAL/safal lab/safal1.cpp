#include <iostream>
using namespace std;
int main() {
    float length, width, perimeter;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;
    perimeter = 2 * (length + width);
    cout << "Perimeter = " << perimeter << endl;
    return 0;
}
