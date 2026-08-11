#include <iostream>
using namespace std;

int main() {
    float sales[7], total = 0, average;

    cout << "Enter sales for 7 days:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> sales[i];
        total += sales[i];
    }

    average = total / 7;

    cout << "\nTotal sales = " << total << endl;
    cout << "Average sales = " << average << endl;
system("pause");
    return 0;
}
