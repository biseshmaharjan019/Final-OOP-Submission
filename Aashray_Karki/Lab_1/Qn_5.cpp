// Assignment Question 2: Swap two numbers without using a temporary variable.

#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    swapNumbers(num1, num2);

    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}