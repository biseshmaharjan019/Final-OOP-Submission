// Task 3: Write a function convertCurrency(float amount, float rate)
// to convert an amount from one currency to another.

#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate, convertedAmount;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter conversion rate: ";
    cin >> rate;

    convertedAmount = convertCurrency(amount, rate);

    cout << "Converted Amount = " << convertedAmount << endl;

    return 0;
}