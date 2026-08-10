#include <iostream>
using namespace std;

void compute(int a, int b)
{
    try
    {
        if (b == 0)
            throw "Division by zero";

        cout << "Result = " << a / b << endl;
    }
    catch (const char *msg)
    {
        cout << "Caught in compute(): " << msg << endl;
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
    catch (const char *msg)
    {
        cout << "Caught again in main(): " << msg << endl;
    }

    return 0;
}
