#include <iostream>
using namespace std;

int main() {
    float sales[7];
    float total = 0;

    cout << "Enter daily sales for 7 days:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> sales[i];
        total += sales[i];
    }

    float average = total / 7;

    cout << "\n--- Sales Report ---\n";
    for (int i = 0; i < 7; i++)
        cout << "Day " << i + 1 << ": $" << sales[i] << endl;

    cout << "Total Sales  : $" << total   << endl;
    cout << "Average Sales: $" << average << endl;

    return 0;
}