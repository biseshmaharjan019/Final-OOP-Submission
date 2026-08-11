#include <iostream>
using namespace std;

int is_prime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int num, count = 0;

    cout << "Enter a number: ";
    cin >> num;

    if (is_prime(num) == 1)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    for (int i = 1; i <= 10; i++) {
        if (is_prime(i) == 1)
            count++;
    }

    cout << "Total prime numbers from 1 to 10 = " << count << endl;

    system("pause");

    return 0;
}