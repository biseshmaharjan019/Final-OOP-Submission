#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, exchangeRate, convertedAmount;

    cout << "Enter the amount in source currency: ";
    cin >> amount;
    cout << "Enter the exchange rate (1 Unit of Source = X Units of Target): ";
    cin >> exchangeRate;

    convertedAmount = convertCurrency(amount, exchangeRate);

    cout << "\nConverted Amount: " << convertedAmount << endl;

    return 0;
}