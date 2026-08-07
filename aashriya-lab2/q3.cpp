#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter exchange rate: ";
    cin >> rate;

    float convertedAmount = convertCurrency(amount, rate);

    cout << "Converted Amount = " << convertedAmount;

    return 0;
}