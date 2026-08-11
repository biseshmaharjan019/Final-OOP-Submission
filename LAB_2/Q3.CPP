// Currency Conversion Using Function

#include <iostream>
#include <cstdlib>
using namespace std;

float convertCurrency(float amount, float rate)
{
    return amount * rate;
}

int main()
{
    float amount, rate;

    cout << "Enter amount and rate: ";
    cin >> amount >> rate;

    cout << "Converted Amount = "
         << convertCurrency(amount, rate) << endl;

    system("pause");
    return 0;
}