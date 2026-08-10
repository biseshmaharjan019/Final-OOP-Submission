#include <iostream>
using namespace std;

int main() {
    float sale[7];
    float total = 0, average;

    cout << "Enter sales for 7 days:\n";

    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> sale[i];
        total =total+ sale[i];
    }
    average = total / 7;
    cout << "\nTotal Sales = " << total << endl;
    cout << "Average Sales = " << average << endl;

    return 0;
}