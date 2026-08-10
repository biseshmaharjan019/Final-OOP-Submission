#include <iostream>
using namespace std;

void swapNumbers(int &ptr1, int &ptr2) {
    int temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int main() {
    int x, y;
    
    cout << "Enter numbers (x & y): ";
    cin >> x >> y;
    
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;

    swapNumbers(x, y);

    cout << "After swap:  x = " << x << ", y = " << y << endl;

    return 0;
}