#include <iostream>
using namespace std;

// User-defined exception for division by zero
class DivideByZeroException
{
public:
    const char* message()
    {
        return "Error: Division by zero is not allowed.";
    }
};

// User-defined exception for negative denominator
class NegativeDenominatorException
{
public:
    const char* message()
    {
        return "Error: Denominator cannot be negative.";
    }
};

int main()
{
    int a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try
    {
        if (b == 0)
            throw DivideByZeroException();

        if (b < 0)
            throw NegativeDenominatorException();

        cout << "Result = " << (double)a / b << endl;
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
