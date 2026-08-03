// Assignment Question 1: Write a C++ program to swap two numbers using a temporary variable and a function.

#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
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