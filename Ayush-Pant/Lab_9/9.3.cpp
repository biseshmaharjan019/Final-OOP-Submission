#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException
{
public:
    string message()
    {
        return "Division by zero is not allowed.";
    }
};

class NegativeDenominatorException
{
public:
    string message()
    {
        return "Negative denominator is not allowed.";
    }
};

int main()
{
    int a, b;

    cout << "Enter numerator and denominator: ";
    cin >> a >> b;

    try
    {
        if (b == 0)
            throw DivideByZeroException();

        if (b < 0)
            throw NegativeDenominatorException();

        cout << "Result = " << a / b << endl;
    }
    catch (DivideByZeroException e)
    {
        cout << e.message() << endl;
    }
    catch (NegativeDenominatorException e)
    {
        cout << e.message() << endl;
    }
    catch (...)
    {
        cout << "Unexpected exception occurred." << endl;
    }

    return 0;
}
