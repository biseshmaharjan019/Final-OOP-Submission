//6.Rewrite the above in C++ using cout.
#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 1; i <= 5; i++) {
        sum = sum + i;
    }

    cout << "Sum of numbers from 1 to 5 = " << sum;

    return 0;
}