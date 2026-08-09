#include<iostream>
using namespace std;

int main() {
    float length, width, perimeter;

    cout << "Enter length and width: ";
    cin >> length >> width;

    perimeter = 2 * (length + width);

    cout << "Perimeter = " << perimeter;

    return 0;
}