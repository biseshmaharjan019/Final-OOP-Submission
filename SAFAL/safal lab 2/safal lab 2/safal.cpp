#include <iostream>
using namespace std;
int main() {
    float sales[7];
    float total = 0, average;
    for(int i = 0; i < 7; i++) {
        cout << "Enter sales for day " << i + 1 << ": ";
        cin >> sales[i];
        total += sales[i];
    }
    average = total / 7;
    cout << "\nTotal Sales = " << total << endl;
    cout << "Average Sales = " << average << endl;
    return 0;
}
