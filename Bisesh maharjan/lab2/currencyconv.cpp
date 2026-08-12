#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate, result;
    cout << "Enter amount:";
    cin >> amount;
    cout << "Enter exchange rate:";
    cin >> rate;
    result = convertCurrency(amount, rate);
    cout << endl;
    cout << "Amount        : " << amount << endl;
    cout << "Exchange Rate : " << rate << endl;
    cout << "Converted     : " << result << endl;

    return 0;
}
