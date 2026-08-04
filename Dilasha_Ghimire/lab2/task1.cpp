
#include <iostream>
using namespace std;

int main() {
    double sales[7];
    double total = 0;
    for (int i = 0; i < 7; i++) {
        cout << "Enter sales for day " << i + 1 << ": ";
        cin >> sales[i];
    }
    for (int i = 0; i < 7; i++) {
        total += sales[i];
    }
    double average = total / 7;

    cout << "\nTotal Sales  : " << total << endl;
    cout << "Average Sales: " << average << endl;

    return 0;
}