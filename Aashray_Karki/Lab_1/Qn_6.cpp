// Assignment Question 3: Write a C++ program to check if a user-input number is prime using a function is_prime().

#include <iostream>
using namespace std;

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (is_prime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}