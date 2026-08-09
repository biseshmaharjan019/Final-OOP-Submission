#include <iostream>
using namespace std;
int main() {
    int sum = 0;

    for(int i = 1; i <= 5; i++) {
        sum = sum + i;
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
