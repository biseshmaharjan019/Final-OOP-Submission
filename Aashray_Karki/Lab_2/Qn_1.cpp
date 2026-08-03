// Task 1: Write a program to store daily sales amounts for a week.
// Calculate and display the total and average sales.

#include <iostream>
using namespace std;

int main() {
    float sales[7], total = 0, average;

    cout << "Enter daily sales for 7 days:" << endl;

    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> sales[i];
        total = total + sales[i];
    }

    average = total / 7;

    cout << "\nTotal Sales = " << total << endl;
    cout << "Average Sales = " << average << endl;

    return 0;
}