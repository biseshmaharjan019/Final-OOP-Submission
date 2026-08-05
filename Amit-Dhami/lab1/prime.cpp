#include <iostream>
using namespace std;
int is_prime(int n) {
int i;
if (n <= 1)
return 0;
for ( i=2;i<n;i++) {
if (n%i==0)
return 0;
    }
return 1;
}
int main() {
int num;
cout << "Enter a number: ";
    cin >> num;
if (is_prime(num) == 1)
cout << num << " is a Prime Number." << endl;
    else
cout << num << " is NOT a Prime Number." << endl;

    return 0;
}
