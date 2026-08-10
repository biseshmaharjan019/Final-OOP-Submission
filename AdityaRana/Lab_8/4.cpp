#include <iostream>
using namespace std;

void compute(int a, int b)
{
    try
    {
        if (b == 0)
            throw b;

        cout << "Result = " << a / b << endl;
    }
    catch (int)
    {
        cout << "Exception caught inside compute()." << endl;
        throw;
    }
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        compute(a, b);
    }
    catch (int)
    {
        cout << "Exception caught again in main()." << endl;
    }

    return 0;
}