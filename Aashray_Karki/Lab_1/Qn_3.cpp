// Question 3: Write a C++ program to print the sum of numbers from 1 to 5 using a for loop.

#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 1; i <= 5; i++) {
        sum = sum + i;
    }

    cout << "Sum of numbers from 1 to 5 = " << sum << endl;

    return 0;
}