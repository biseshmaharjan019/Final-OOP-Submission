#include <iostream>
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
    for(int i = 1; i <= num; i++) {
        if(is_prime(i)) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nTotal prime numbers = " << count << endl;

    return 0;
}
