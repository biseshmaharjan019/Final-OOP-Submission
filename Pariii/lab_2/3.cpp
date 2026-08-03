#include <iostream>
using namespace std;

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate;

    cout << "Enter amount to convert : ";
    cin  >> amount;
    cout << "Enter conversion rate   : ";
    cin  >> rate;

    float converted = convertCurrency(amount, rate);

    cout << "\n" << amount << " (original) = "
         << converted << " (converted)" << endl;

    return 0;
}