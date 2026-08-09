// Assignment Question 4: Count how many numbers from 1 to the input number are prime.

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
    int number, count = 0;

    cout << "Enter a number: ";
    cin >> number;

    for (int i = 1; i <= number; i++) {
        if (is_prime(i)) {
            count++;
        }
    }

    cout << "Total prime numbers from 1 to " << number << " = " << count << endl;

    return 0;
}