#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= n - 1; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (is_prime(num))
        cout << num << " is a prime number" << endl;
    else
        cout << num << " is not a prime number" << endl;

    return 0;
}