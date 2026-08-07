#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate, result;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter exchange rate: ";
    cin >> rate;

    result = convertCurrency(amount, rate);

    cout << "\nConverted Amount: " << result << endl;

    return 0;
}