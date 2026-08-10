#include <iostream>
using namespace std;

int main() {
    double sales[7];
    double totalSales = 0.0;
    double averageSales = 0.0;

    cout << "Enter the sales amounts for 7 days:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Day " << (i + 1) << ": ";
        cin >> sales[i];
        totalSales += sales[i];
    }

    averageSales = totalSales / 7.0;

    cout << "\n--- Sales Report ---" << endl;
    cout << "Total Sales for the week: " << totalSales << endl;
    cout << "Average Daily Sales: " << averageSales << endl;

    return 0;
}