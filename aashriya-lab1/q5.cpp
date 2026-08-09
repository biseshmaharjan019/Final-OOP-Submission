#include<iostream>
using namespace std;

bool is_prime(int n) {

    if(n <= 1)
        return false;

    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int num, count = 0;

    cout << "Enter a number: ";
    cin >> num;

    if(is_prime(num))
        cout << num << " is Prime" << endl;
    else
        cout << num << " is Not Prime" << endl;

    for(int i = 1; i <= num; i++) {
        if(is_prime(i))
            count++;
    }

    cout << "Total prime numbers from 1 to "
         << num << " = " << count;

    return 0;
}