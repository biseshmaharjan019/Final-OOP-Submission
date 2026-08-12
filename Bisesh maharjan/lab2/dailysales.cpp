#include <iostream>
using namespace std;

int main() {
    float sales[7], total = 0, avg;
    int i;
   for (i= 0; i < 7; i++) {
        cout << "Enter sales for the day ";
        cin >> sales[i];
        total += sales[i];
    }
     avg = total / 7;
    cout << endl << "Total Sales:" << total << endl;
    cout << "Average Sales:" << avg << endl;
    return 0;
}
