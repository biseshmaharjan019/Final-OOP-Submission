#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter conversion rate: ";
    cin >> rate;

    cout << "Converted amount = " << convertCurrency(amount, rate) << endl;
system("pause");
    return 0;
}
